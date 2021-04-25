package DMOJ;
import java.util.Scanner;

public class Emoji_Search {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String S = in.nextLine();
		
		int colon = -1;
		boolean isLeft = true;
		
		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) == ':') {
				if (colon != -1 && isLeft) {
					System.out.println(S.substring(colon + 1, i));
					isLeft = false;
				} else {
					isLeft = true;
				}
				colon = i;
			}
		}
	}

}
