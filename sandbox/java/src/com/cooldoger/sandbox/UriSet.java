package com.cooldoger.sandbox;

import java.util.HashSet;
import java.util.Set;
import java.net.URI;

public class UriSet {
	private static final String[] URI_NAMES = {
		"http://cooldoger.googlecode.com",
		"http://www.cooldoger.com",
		"http://www.ebay.com",
		"http://www.cooldoger.com",
		"http://cooldoger.com",
		"http://www.baidu.com",
	};
	
	public static void main(String[] args) {
		Set<URI> favorites = new HashSet<URI>();
		for (String uriName : URI_NAMES)
			favorites.add(URI.create(uriName));
		System.out.println(favorites.size());
	}

}
