package COCI;
import java.util.Scanner;

public class COCI_2006_C6_P4 {

	static int R, C;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		R = in.nextInt();
		C = in.nextInt();
		in.nextLine();
		
		char[][] board = new char[R][];
		for (int i = 0; i < R; i++) {
			board[i] = in.nextLine().toCharArray();
		}
		
		for (int k = 0; k < R; k++) {
			for (int l = 0; l < C; l++) {
				System.out.print(board[k][l]);
			}
			System.out.println();
		}
	}

}