package com.cooldoger.sandbox;

import java.util.HashSet;
import java.util.Set;
import java.net.MalformedURLException;
import java.net.URL;

public class UrlSet {
	private static final String[] URL_NAMES = {
		"http://cooldoger.googlecode.com",
		"http://www.cooldoger.com",
		"http://www.ebay.com",
		"http://www.cooldoger.com",
		"http://cooldoger.com",
		"http://www.baidu.com",
	};
	
	public static void main(String[] args) 
	throws MalformedURLException 
	{
		Set<URL> favorites = new HashSet<URL>();
		for (String urlName : URL_NAMES)
			favorites.add(new URL(urlName));
		System.out.println(favorites.size());
	}
}
