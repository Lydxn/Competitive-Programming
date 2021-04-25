package DMOJ;
import java.util.Scanner;

public class Ship {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String parts = in.nextLine();
		
		boolean[] letters = new boolean[5];
		for (int i = 0; i < parts.length(); i++) {
			letters["BFTLC".indexOf(parts.charAt(i))] = true;
		}
		
		boolean missing = false;
		for (int i = 0; i < letters.length; i++) {
			if (!letters[i]) {
				System.out.println("BFTLC".charAt(i));
				missing = true;
			}
		}
		
		if (!missing) {
			System.out.println("NO MISSING PARTS");
		}
	}

}