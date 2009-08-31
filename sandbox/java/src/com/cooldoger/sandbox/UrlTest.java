package com.cooldoger.sandbox;

import java.net.MalformedURLException;
import java.net.URL;

public class UrlTest {

	public static void main(String[] args)
	throws MalformedURLException
	{
		URL[] URLS = {
		new URL("http://cooldoger.com"),
		new URL("http://www.cooldoger.com"),
		new URL("http://cooldoger.net"),
		new URL("http://cooldoger.cn"),
		new URL("http://google.com"),
		new URL("http://google.net"),
		new URL("http://cooldoger.googlecode.com"),
		};
		
		for (URL url1 : URLS){
			for (URL url2 : URLS){
				String tmp = url1.equals(url2)? "1 ":"0 ";
				System.out.print(tmp);
			}
			System.out.println();
		}		
	}
}
