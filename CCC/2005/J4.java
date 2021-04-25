package ccc_2005;
import java.util.Arrays;
import java.util.Scanner;

public class J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int W = in.nextInt();
		int H = in.nextInt();
		int cW = in.nextInt();
		int cH = in.nextInt();
		int steps = in.nextInt();
		
		boolean[][] room = new boolean[H][W];
		for (int i = 0; i < cH; i++) {
			Arrays.fill(room[i], 0, cW, true);
			Arrays.fill(room[i], W - cW, W, true);
		}
		
		for (int j = H - 1; j >= H - cH; j--) {
			Arrays.fill(room[j], 0, cW, true);
			Arrays.fill(room[j], W - cW, W, true);
		}
		
		int[][] dir = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
		int x = cW;
		int y = 0;
		int face = 0;

		for (int i = 0; i < steps; i++) {
			room[y][x] = true;

			int j = 0;
			for (; j < 4; j++) {	
				int nextX = x + dir[(j + face) % 4][0];
				int nextY = y + dir[(j + face) % 4][1];
				
				if (nextX >= 0 && nextX < W && nextY >= 0 && nextY < H && !room[nextY][nextX]) {
					x = nextX;
					y = nextY;
					break;
				}
			}
			face += j - 1;
		}
		System.out.println((x + 1) + "\n" + (y + 1));
	}

}
