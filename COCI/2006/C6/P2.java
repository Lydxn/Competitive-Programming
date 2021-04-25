package COCI;
import java.util.Scanner;

public class COCI_2006_C6_P2 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int R = in.nextInt();
		int C = in.nextInt();
		in.nextLine();
		
		char[][] card = new char[R * 2][C * 2];
		
		for (int i = 0; i < R; i++) {
			String row = in.nextLine();
			for (int j = 0; j < C; j++) {
				card[i][j] = row.charAt(j);
				card[2 * R - i - 1][j] = row.charAt(j);
				card[i][2 * C - j - 1] = row.charAt(j);
				card[2 * R - i - 1][2 * C - j - 1] = row.charAt(j);
			}
		}

		int A = in.nextInt() - 1;
		int B = in.nextInt() - 1;
		card[A][B] = card[A][B] == '#' ? '.' : '#';
		
		for (int k = 0; k < R * 2; k++) {
			for (int l = 0; l < C * 2; l++) {
				System.out.print(card[k][l]);
			}
			System.out.println();
		}
	}

}