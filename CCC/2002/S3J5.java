package ccc_2002;
import java.util.Scanner;

public class S3_J5 {

	static char[] moves;
	static char[][] yard; 
	static int r, c, m;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		r = in.nextInt();
		c = in.nextInt();
		in.nextLine();
		
		yard = new char[r][];
		for (int i = 0; i < r; i++) {
			yard[i] = in.nextLine().toCharArray();
		}
		
		m = in.nextInt();
		in.nextLine();
		
		moves = new char[m];
		for (int i = 0; i < m; i++) {
			moves[i] = in.nextLine().charAt(0);
		}
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				for (int k = 0; k < 360; k += 90) {
					check(i, j, k);
				}
			}
		}
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				System.out.print(yard[i][j]);
			}
			System.out.println();
		}
	}
	
	private static void check(int x, int y, int dir) {
		for (int i = 0; i < m && x >= 0 && x < r && y >= 0 && y < c && (yard[x][y] == '.' || yard[x][y] == '*'); i++) {
			if (moves[i] == 'R') {
				dir = (dir - 90) % 360;
			} else if (moves[i] == 'L') {
				dir = (dir + 90) % 360;
			} else if (moves[i] == 'F') {
				if (dir == 0) {
					x++;
				} else if (dir == 90) {
					y++;
				} else if (dir == 180) {
					x--;
				} else {
					y--;
				}
			}
		}
		
		if (x >= 0 && x < r && y >= 0 && y < c && yard[x][y] == '.') {
			yard[x][y] = '*';
		}
	}
}
