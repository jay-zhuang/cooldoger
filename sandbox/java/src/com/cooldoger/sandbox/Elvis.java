package com.cooldoger.sandbox;

public class Elvis {
	// Singleton pattern: there's only one Elvis
	public static final Elvis ELVIS = new Elvis();
	private Elvis() { }
	
	private static final Boolean LIVING = true;
	
	private final Boolean alive = LIVING;
	
	public final Boolean lives() { return alive; }
	
	public static void main(String[] args) {
		System.out.println(ELVIS.lives() ? 
				"Shanghai" : "Beijing");
	}
}
