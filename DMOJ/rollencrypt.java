package DMOJ;
import java.util.Scanner;

public class Rolling_Encryption {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		in.nextLine();
		
		char[] chars = in.nextLine().toCharArray();
		for (int i = 0; i < k; i++) {
			System.out.print(chars[i]);
		}
		
		for (int i = k; i < chars.length; i++) {
			int[] freq = new int[26];
			for (int j = i - k; j < i; j++) {
				freq[chars[j] - 'a']++;
			}

			int maxFreq = 0;
			int maxIndex = 0;
			for (int j = 0; j < freq.length; j++) {
				if (maxFreq < freq[j]) {
					maxFreq = freq[j];
					maxIndex = j;
				}
			}
			System.out.print((char) ((chars[i] - 'a' + maxIndex + 1) % 26 + 'a'));
		}
	}

}