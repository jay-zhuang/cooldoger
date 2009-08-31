package com.cooldoger.sandbox;

public class JunitTest extends junit.framework.TestCase{
	int number;
	
	public void test() throws InterruptedException {
		number = 0;
		Thread t = new Thread(new Runnable() {
			public void run() {
				assertEquals(2, number);
			}
		});
		number = 2;
		t.start();
		number++;
		t.join();
	}
}
