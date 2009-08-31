package com.cooldoger.sandbox;

public class JunitTestPro extends junit.framework.TestCase {
	int number;
	
	public void test() throws InterruptedException {
		number = 0;
		Thread t = new Thread(new Runnable() {
			public void run() {
				try {
					assertEquals(2, number);
				} catch (Error e) {
					error = e;
				} catch (Exception e) {
					exception = e;
				}
			}
		});
		number = 1;
		t.start();
		number++;
		t.join();
	}

	volatile Exception exception;
	volatile Error error;
	
	// Triggers test case failure if any thread asserts failed
	public void tearDown() throws Exception {
		if (error != null)
			throw error;
		if (exception != null)
			throw exception;
	}
}
