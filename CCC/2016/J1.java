package ccc_2016;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		String[] games = new String[6];
		int winCount = 0;

		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 6; i++) {
			games[i] = in.nextLine();
		}
		
		for (int j = 0; j < 6; j++) {
			if (games[j].equals("W")) {
				winCount++;
			}
 		}

		if (winCount == 6 || winCount == 5) {
			System.out.println('1');
		} else if (winCount == 3 || winCount == 4) {
			System.out.println('2');
		} else if (winCount == 1 || winCount == 2) {
			System.out.println('3');
		} else {
			System.out.println("-1");
		}
	}

}
