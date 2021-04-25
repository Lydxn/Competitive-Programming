package ccc_2012;
import java.util.Scanner;

public class J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int K = in.nextInt();
		in.nextLine();
		String word = in.nextLine();
		
		String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for (int i = 0; i < word.length(); i++) {
			char letter = word.charAt(i);
			int shiftValue = 3 * (i + 1) + K;
			
			int encoded = alphabet.indexOf(letter) - shiftValue;
			if (encoded < 0) {
				encoded += 26;
			}
			System.out.print(alphabet.charAt(encoded));
		}
	}

}
