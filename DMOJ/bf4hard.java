package DMOJ;
import java.util.Scanner;

public class String_Finding_Hard {
	
	static final int MAX_CHAR = 256;
	static final int PRIME = 31;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String S = in.nextLine();
		String T = in.nextLine();
		
		System.out.println(rabinKarp(S, T));
	}
	
	private static int rabinKarp(String str, String pat) {
		int sLen = str.length();
		int pLen = pat.length();
		int sHash = 0;
		int pHash = 0;
		int hash = 1;
		int j;
		
		for (int i = 0; i < pLen - 1; i++) {
			hash = (hash * MAX_CHAR) % PRIME;
		}
		
		for (int i = 0; i < pLen; i++) {
			sHash = (MAX_CHAR * sHash + str.charAt(i)) % PRIME;
			pHash = (MAX_CHAR * pHash + pat.charAt(i)) % PRIME;
		}
	
		for (int i = 0; i <= sLen - pLen; i++) { 
			if (sHash == pHash) {
				for (j = 0; j < pLen && str.charAt(i + j) == pat.charAt(j); j++);
				if (j == pLen) {
					return i;
				}
			}
			
			if (i < sLen - pLen) {
				sHash = (MAX_CHAR * (sHash - str.charAt(i) * hash) + str.charAt(i + pLen)) % PRIME;
				if (sHash < 0) {
					sHash += PRIME;
				}
			}
		}
		return -1;
	}

}