package DMOJ;
import java.util.Scanner;

public class _4Ever {

	static String[] to20 = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
	static String[] tens = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		do {
			System.out.println(N = toWords(N).length());
		} while (N != 4);
	}
	
	private static String toWords(int N) {
		if (N >= 1E9) {
			return toWords(N / (int) 1E9) + "billion" + toWords(N % (int) 1E9);
		} else if (N >= 1E6) {
			return toWords(N / (int) 1E6) + "million" + toWords(N % (int) 1E6);
		} else if (N >= 1E3) {
			return toWords(N / (int) 1E3) + "thousand" + toWords(N % (int) 1E3);
		} else if (N >= 1E2) {
			return toWords(N / (int) 1E2) + "hundred" + toWords(N % (int) 1E2);
		} else if (N >= 2E1) {
			return tens[N / (int) 1E1] + toWords(N % (int) 1E1);
		} else {
			return to20[N];
		}
	}

}
