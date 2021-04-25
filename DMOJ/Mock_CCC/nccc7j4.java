import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String A = in.nextLine();
		String B = in.nextLine();

		int[] alpha = new int[26];
		for (int i = 0; i < A.length(); i++) {
			alpha[A.charAt(i) - 'A']++;
		}

		for (int i = 0; i < B.length(); i++) {
			alpha[B.charAt(i) - 'A']--;
		}

		int candles = 0;
		for (int i = 0; i < alpha.length; i++) {
			candles += Math.max(alpha[i], 0);
		}
		System.out.println(candles);
	}


}
