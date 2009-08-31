package com.cooldoger.sandbox;

import java.io.*;

public class GapPro {
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
//		in.skip(GAP_SIZE);
		skipFully(in, GAP_SIZE);
		int last = in.read();
		System.out.println(first + last);
	}
	
	static void skipFully(InputStream in, long nBytes) 
			throws IOException {
		long remaining = nBytes;
		while (remaining != 0) {
			long skipped = in.skip(remaining);
			if (skipped == 0)
				throw new EOFException();
			remaining -= skipped;
		}
	}
}
