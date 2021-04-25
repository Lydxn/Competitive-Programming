package DMOJ;
import java.util.Scanner;

public class Rinslet_Laurenfrost {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String word1 = in.nextLine();
		String word2 = in.nextLine();
		
		int[] freq = new int[26];
		
		for (int i = 0; i < word1.length(); i++) {
			freq[word1.charAt(i) - 'a']++;
		}
		
		for (int i = 0; i < word2.length(); i++) {
			freq[word2.charAt(i) - 'a']--;
		}
		
		int similarity = 0;
		for (int f : freq) {
			similarity += Math.abs(f);
		}
		System.out.println(similarity);
	}

}
