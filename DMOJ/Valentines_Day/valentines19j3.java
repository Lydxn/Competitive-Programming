package DMOJ.Valentines_Day;
import java.util.Scanner;

public class Valentines_Day_2019_J3 {
	
	static long[][] cache;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String S = in.nextLine();
		
		cache = new long[S.length() + 1][5];
		System.out.println(occurrences(S, "love", S.length(), 4));
	}
	
	private static long occurrences(String S, String sub, int sLen, int subLen) {	
		if ((sLen == 0 && subLen == 0) || subLen == 0) {
			return 1;
		} else if (sLen == 0) {
			return 0;
		}
		
		if (cache[sLen][subLen] != 0) {
			return cache[sLen][subLen];
		} else if (S.charAt(sLen - 1) == sub.charAt(subLen - 1)) {
			return cache[sLen][subLen] = occurrences(S, sub, sLen - 1, subLen - 1) + 
										 occurrences(S, sub, sLen - 1, subLen);
		} else {
			return cache[sLen][subLen] = occurrences(S, sub, sLen - 1, subLen); 
		}
	}
	
}
