package COCI;
import java.util.Scanner;

public class COCI_2007_C4_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String word = in.nextLine();
		
		String smallest = word;
		for (int i = 1; i < word.length() - 1; i++) {
			for (int j = i + 1; j < word.length(); j++) {
				StringBuilder part1 = new StringBuilder(word.substring(0, i)).reverse();
				StringBuilder part2 = new StringBuilder(word.substring(i, j)).reverse();
				StringBuilder part3 = new StringBuilder(word.substring(j)).reverse();
				String newWord = part1.toString() + part2.toString() + part3.toString();
				if (lexico(smallest, newWord) > 0) {
					smallest = newWord;
				}
			}
		}
		System.out.println(smallest);
	}
	
	public static int lexico(String s1, String s2) {
		for (int i = 0; i < s1.length(); i++) {
			if (s1.charAt(i) != s2.charAt(i)) {
				return Integer.valueOf(s1.charAt(i)).compareTo(Integer.valueOf(s2.charAt(i)));
			}
		}
		return 0;
	}

}
