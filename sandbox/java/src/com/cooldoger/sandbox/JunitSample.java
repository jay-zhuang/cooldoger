package com.cooldoger.sandbox;

import junit.framework.AssertionFailedError;

public class JunitSample extends junit.framework.TestCase{

	public void test() throws InterruptedException {
		int number = 1;
		try {
			assertEquals(1, number);
			System.out.println("1");
			assertEquals(2, number);
			System.out.println("2");
		}catch (AssertionFailedError e){
			System.out.println("error!");
		}
	}
}
