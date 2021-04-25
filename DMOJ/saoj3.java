package DMOJ;
import java.util.Scanner;

public class Sword_Art_Online_Judge_3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int[] alpha = new int[26];
		while (in.hasNextLine()) {
			String str = in.nextLine().toUpperCase();
			for (int i = 0; i < str.length(); i++) {
				if (Character.isAlphabetic(str.charAt(i))) {
					alpha[str.charAt(i) - 'A']++;
				}
			}
		}
		
		for (int a : alpha) {
			System.out.print(a + " ");
		}
	}

}
