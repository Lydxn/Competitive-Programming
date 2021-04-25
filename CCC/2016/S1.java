package ccc_2016;
import java.util.Scanner;

public class S1 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s1 = in.nextLine();
		String s2 = in.nextLine();
		
		int[] letters = new int[26];
		for (int i = 0; i < s1.length(); i++) {
			letters[s1.charAt(i) - 97]++;
		}
		
		boolean anagram = true;
		for (int j = 0; j < s2.length(); j++) {
			if (s2.charAt(j) == '*') {
				continue;
			}
			
			if (letters[s2.charAt(j) - 97] == 0) {
				anagram = false;
			} else {
				letters[s2.charAt(j) - 97]--;
			}
		}
		System.out.println(anagram ? 'A' : 'N');
	}
	
}
