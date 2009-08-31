package com.cooldoger.sandbox;

import java.util.HashMap;
import java.util.Map;

public class MapSet {
	public static void main(String[] args) {
		Map<Short,String> m = new HashMap<Short,String>();
		for(short i = 0; i < 100; i++) {
			m.put(i,"Hi");
			m.remove(i - 1);
		}
		System.out.print(m.size());
	}
}
