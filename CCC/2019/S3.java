import java.util.Scanner;

public class S3 {

	static int[][] grid = new int[3][3];
	static int[][] check = {{1, 1}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {0, 0}, {0, 2}, {2, 0}, {2, 2}};
	static int[] rowX = new int[3];
	static int[] colX = new int[3];
	static int countX = 0;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				String val = in.next();
				if (val.equals("X")) {
					grid[i][j] = Integer.MAX_VALUE;
					rowX[i]++;
					colX[j]++;
					countX++;
				} else {
					grid[i][j] = Integer.parseInt(val);
				}
			}
		}

		outer: while (countX > 0) {
			for (int i = 0; i < 3; i++) {
				if (rowX[i] == 1) {
					fillRow(i);
					continue outer;
				}
			}

			for (int i = 0; i < 3; i++) {
				if (colX[i] == 1) {
					fillCol(i);
					continue outer;
				}
			}

			for (int[] c : check) {
				int x = c[1];
				int y = c[0];

				if (grid[y][x] == Integer.MAX_VALUE) {
					grid[y][x] = 0;
					rowX[y]--;
					colX[x]--;
					countX--;
					continue outer;
				}
			}
		}

		for (int[] i : grid) {
			for (int j : i) {
				System.out.print(j + " ");
			}
			System.out.println();
		}
	}

	private static void fillRow(int y) {
		int xPos = 0;
		for (int i = 0; i < grid.length; i++) {
			if (grid[y][i] == Integer.MAX_VALUE) {
				xPos = i;
			}
		}

		grid[y][xPos] = xPos == 0 ? 2 * grid[y][1] - grid[y][2] :
						xPos == 1 ? (grid[y][0] + grid[y][2]) / 2 :
									2 * grid[y][1] - grid[y][0];
		rowX[y]--;
		colX[xPos]--;
		countX--;
	}

	private static void fillCol(int x) {
		int xPos = 0;
		for (int i = 0; i < grid.length; i++) {
			if (grid[i][x] == Integer.MAX_VALUE) {
				xPos = i;
			}
		}

		grid[xPos][x] = xPos == 0 ? 2 * grid[1][x] - grid[2][x] :
						xPos == 1 ? (grid[0][x] + grid[2][x]) / 2 :
									2 * grid[1][x] - grid[0][x];
		rowX[xPos]--;
		colX[x]--;
		countX--;
	}

}
