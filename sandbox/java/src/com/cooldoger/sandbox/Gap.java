package com.cooldoger.sandbox;

import java.io.*;

public class Gap {
	private static final int GAP_SIZE = 10 * 1024;
	public static void main(String[] args) 
		throws IOException
	{
		File tmp = File.createTempFile("gap", ".txt");
		FileOutputStream out = new FileOutputStream(tmp);
		out.write(1);
		out.write(new byte[GAP_SIZE]);
		out.write(2);
		out.close();
		InputStream in = new BufferedInputStream(new FileInputStream(tmp));
		int first = in.read();
		in.skip(GAP_SIZE);
		int last = in.read();
		System.out.println(first + last);
	}
}
