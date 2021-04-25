import java.io.*;
import java.util.*;

public class P2 {
    private static char[][] board = new char[3][];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++) {
				board[j] = in.nextLine().toCharArray();
			}

			int[][] wins = {{0, 0, 0, 1}, {1, 0, 0, 1}, {2, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 2, 1, 0}, {0, 0, 1, 1}, {2, 0, -1, 1}};
			char winner = '.';

			for (int k = 0; k < wins.length; k++) {
				char res = check(wins[k][0], wins[k][1], wins[k][2], wins[k][3]);
				if (res == 'X' || res == 'O') {
					winner = res;
					break;
				}
			}
			System.out.println(winner);
		}
	}

	private static char check(int x, int y, int dx, int dy) {
		char res = board[y][x];
		for (int i = 0; i < 3; i++, x += dx, y += dy) {
			if (res != board[y][x]) {
				res = '.';
				break;
			}
		}
		return res;
	}
}
