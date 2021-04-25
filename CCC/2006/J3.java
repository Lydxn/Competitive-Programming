package ccc_2006;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		int[][] secsArr = { 
		{1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4},
		{2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9}};
		
		Scanner in = new Scanner(System.in);
		while (true) {
			String word = in.nextLine();
			if (word.equals("halt")) {
				return;
			}

			int secs = 0;
			for (int i = 0; i < word.length(); i++) {
				secs += secsArr[0][Character.codePointAt(word, i) - 97];
				if (i > 0 && secsArr[1][word.charAt(i) - 97] == 
							 secsArr[1][word.charAt(i - 1) - 97]) {
					secs += 2;
				}
			}
			System.out.println(secs);
		}
			
	}

}
