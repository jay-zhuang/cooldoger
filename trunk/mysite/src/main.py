import wsgiref.handlers
import os
import xml.dom.minidom
import feedparser
import datetime
import time

from operator import attrgetter
from time import strftime, strptime, gmtime
from xml.dom.minidom import Node
from google.appengine.ext.webapp import template
from google.appengine.api import users
from google.appengine.ext import webapp
from google.appengine.ext import db
from google.appengine.api import urlfetch

class Account(db.Expando):
    user = db.UserProperty()
    
class Entry:
    def __init__(self=None, title=None, link=None, timestamp=None, content=None, service=None):
        self.title = title
        self.link = link
        self.content = content
        self.service = service
        self.timestamp = timestamp
    def printTime(self):
        return strftime('%B %d,%Y at %I:%M:%S %p',self.timestamp)            

class GenericFeed:
    def __init__(self, url, name):
        self.url = url
        self.name = name
    def entries(self):
        result = urlfetch.fetch(self.url)
        updates = []
        if result.status_code == 200:
            feed = feedparser.parse(result.content)
            for entry in feed['entries']:
                x = Entry()
                x.service = self.name
                x.title = entry['title']
                x.link = entry['link']
                if entry.summary:
                    x.content = entry.summary
                else:
                    x.content = entry['title']
                x.timestamp = entry.updated_parsed
                updates.append(x)
        return updates          

class MainPage(webapp.RequestHandler):
  def get(self):
    user = users.get_current_user()

    if users.get_current_user():
      url = users.create_logout_url(self.request.uri)
      url_linktext = 'Logout'
    else:
      url = users.create_login_url(self.request.uri)
      url_linktext = 'Login'
      
    updates = []
    account = None
    if user:
        account_query = Account.all()
        account_query.filter('user = ', users.get_current_user())
        result_set = account_query.fetch(1)
        if len(result_set) > 0:
            account = account_query.fetch(1)[0]
        
        if account:
            updates = []
            for service in account.dynamic_properties():
                url = getattr(account, service)
                feed = GenericFeed(url, service)
                updates.extend(feed.entries())
        else:
            account = Account()
            account.user = user
            account.put()
        updates.sort(key=attrgetter('timestamp'), reverse=True)

    template_values = {
      'account': account,
      'updates': updates,
      'url': url,
      'url_linktext': url_linktext,
      }

    path = os.path.join(os.path.dirname(__file__), 'index.html')
    self.response.out.write(template.render(path, template_values))

class AddService(webapp.RequestHandler):
    def post(self):
        # check if user already exists
        account_query = Account.all()
        account_query.filter('user = ', users.get_current_user())
        result_set = account_query.fetch(1)
        if len(result_set) > 0:
            account = account_query.fetch(1)[0]
        else :
            account = Account()
            account.user = users.get_current_user()
        service = self.request.get('service')
        username = self.request.get('username')
        if service == 'twitter':
            service = 'http://twitter.com/statuses/user_timeline/'+username+'.rss'
            account.twitter = service
        if service =='del.icio.us':
            service = 'http://del.icio.us/rss/' + username
            account.del_icio_us = service
        if service == 'last.fm':
            service = 'http://ws.audioscrobbler.com/1.0/user/'+username+'/recenttracks.rss'
            account.last_fm = service
        if service == 'YouTube':
            service = 'http://www.youtube.com/rss/user/'+username+'/videos.rss'
            account.you_tube = service
        account.put()
        self.redirect('/')
        
def main():
    application = webapp.WSGIApplication(
                                         [('/', MainPage),
                                          ('/add', AddService)],
                                          debug=True)
    wsgiref.handlers.CGIHandler().run(application)
    
if __name__ == "__main__":
    main()