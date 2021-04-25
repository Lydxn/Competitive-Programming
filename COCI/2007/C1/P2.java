package COCI;
import java.util.Scanner;

public class COCI_2007_C1_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		char[][] peg = new char[7][];
		for (int i = 0; i < 7; i++) {
			peg[i] = in.nextLine().toCharArray();
		}
		
		int moves = 0;
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 7; k++) {
				if (peg[j][k] == '.') {
					if (j < 5 && peg[j + 1][k] == 'o' && peg[j + 2][k] == 'o') {
						moves++;
					}
					if (j > 1 && peg[j - 1][k] == 'o' && peg[j - 2][k] == 'o') {
						moves++;
					}
					if (k < 5 && peg[j][k + 1] == 'o' && peg[j][k + 2] == 'o') {
						moves++;
					}
					if (k > 1 && peg[j][k - 1] == 'o' && peg[j][k - 2] == 'o') {
						moves++;
					}
				}
			}
		}
		System.out.println(moves);
	}

}