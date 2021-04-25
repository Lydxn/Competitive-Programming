import java.util.*;
import java.io.*;

public class P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();

		int minX = Integer.MAX_VALUE;
		int maxX = Integer.MIN_VALUE;
		int minY = Integer.MAX_VALUE;
		int maxY = Integer.MIN_VALUE;

		boolean[][] grid = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				char ch = in.next().charAt(0);
				grid[i][j] = ch == '.' ? false : true;

				if (ch == '*') {
					minX = Math.min(minX, j);
					maxX = Math.max(maxX, j);
					minY = Math.min(minY, i);
					maxY = Math.max(maxY, i);
				}
			}
		}

		for (int y = minY; y <= maxY; y++) {
			for (int x = minX; x <= maxX; x++) {
				System.out.print((grid[y][x] == false ? '.' : '*') + " ");
			}
			System.out.println();
		}
	}

}
