package com.cooldoger.sandbox;

public class ElvisPro {
	// Singleton pattern: there's only one Elvis

	private ElvisPro() { }
	
	private static final Boolean LIVING = true;
	public static final ElvisPro ELVIS = new ElvisPro();	
	private final Boolean alive = LIVING;
	
	public final Boolean lives() { return alive; }
	
	public static void main(String[] args) {
		System.out.println(ELVIS.lives() ? 
				"Shanghai" : "Beijing");
	}
}
