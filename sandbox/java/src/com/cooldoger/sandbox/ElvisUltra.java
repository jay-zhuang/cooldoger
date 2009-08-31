package com.cooldoger.sandbox;

public class ElvisUltra {
	// Singleton pattern: there's only one Elvis
	public static final ElvisUltra ELVIS = new ElvisUltra();
	private ElvisUltra() { }
	
	private static final boolean LIVING = true;
	
	private final Boolean alive = LIVING;
	
	public final Boolean lives() { return alive; }
	
	public static void main(String[] args) {
		System.out.println(ELVIS.lives() ? 
				"Shanghai" : "Beijing");
	}
}
