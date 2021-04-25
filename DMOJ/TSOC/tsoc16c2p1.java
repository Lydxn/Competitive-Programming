package DMOJ;
import java.util.Scanner;

public class Mary_Jane_And_Invitations {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();

		char[] invites = new char[N];
		String S = in.nextLine();
		
		for (int i = 0, guest = 0; i < S.length(); i++) {
			if (S.charAt(i) != 'X') {
				invites[guest++] = S.charAt(i);
			} else {
				int prev;
				for (prev = 0; S.charAt(i) == 'X'; prev++) {
					i++;
				}
				invites[guest - prev] = S.charAt(i);
			}
		}
		
		for (char i : invites) {
			String name = in.nextLine();
			System.out.print("Dear " + name + ", ");
			
			switch (i) {
			case 'A':
				System.out.println("beloved artist, I would love to have you at my party. Come to my crib on April 20th.");
				break;
			case 'O':
				System.out.println("beloved occasion enthusiast, come to my crib to celebrate this very special day.");
				break;
			case 'R':
				System.out.println("April 20th is happening again this year. Don't miss out.");
				break;
			}
		}
	}

}
