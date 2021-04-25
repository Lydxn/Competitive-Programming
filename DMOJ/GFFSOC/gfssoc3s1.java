package DMOJ;

import java.util.Scanner;

public class OR_Deal {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long N = in.nextLong();
		
		long log2 = 0;
		for (; N > 0; N >>= 1, log2++);
		System.out.println(Long.toBinaryString((1L << log2) - 1));
	}

}