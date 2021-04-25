package COCI;
import java.util.Scanner;

public class COCI_2006_C3_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		char[][] puzzle = new char[4][];
		for (int i = 0; i < 4; i++) {
			puzzle[i] = in.nextLine().toCharArray();
		}
		
		int scatter = 0;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (puzzle[j][k] != '.') {
					int value = puzzle[j][k] - 65;
					int x = value / 4;
					int y = value % 4;
					scatter += Math.abs(x - j) + Math.abs(y - k);
				}
			}
		}
		System.out.println(scatter);
	}

}
