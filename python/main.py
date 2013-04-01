#!/usr/bin/env python

import sys
import datetime

class Account(object) :
    num_account = 0

    def __init__(self, name, balance):
        self.name = name
        self.balance = balance

    def deposit(self, num):
        self.balance += num

    def withdraw(self, num):
        self.balance -= num

def main():
    a = Account("jay", 10)
    b = Account("joe", 200)
    a.deposit(11)
    print a.balance
    Account.deposit(a, 33)
    print a.balance
    history = {
            'event' : {
                'day' : 0,
                },
            'metadata' : {
                'closed' : 'true',
                },
            }
    print history
    history['metadata']['closed'] = 'false'
    print history
    now = datetime.datetime.now()
    print now.strftime("%Y-%m-%d %I:%M:%S%p %Z")
    print ("bb" + "aaa") if a is None else "bbb"
    print ("bb" + "aaa") if a is not None else "bbb"
    aaa = "aaa"
    aaa += "bb"
    print aaa

if __name__ == '__main__':
    main()

