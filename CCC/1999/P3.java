package ccc_1999;
import java.util.Scanner;

public class P3 {
	
	static String[][] menger = new String[243][243];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int d = in.nextInt();
		
		for (int i = 0; i < d; i++) {
			int n = in.nextInt();
			int b = in.nextInt();
			int t = in.nextInt();
			int l = in.nextInt();
			int r = in.nextInt();

			int exp = (int) Math.pow(3, n);
			for (int j = 0; j < exp; j++) {
				for (int k = 0; k < exp; k++) {
					menger[j][k] = "*";
				}
			}
			square(0, 0, n);
			
			for (int j = t - 1; j >= b - 1; j--) {
				for (int k = l - 1; k < r; k++) {
					System.out.print(menger[j][k] + "  ");
				}
				System.out.println();
			}
			System.out.println();
		}
		
	}
	
	private static void square(int x, int y, int iter) {
		int n = (int) Math.pow(3, iter - 1);
		if (iter == 0) {
			return;
		}

		for (int i = x + n; i < 2 * n + x; i++) {
			for (int j = y + n; j < 2 * n + y; j++) {
				menger[i][j] = " ";
			}
		}
		
		for (int a = 0; a <= 2; a++) {
			for (int b = 0; b <= 2; b++) {
				square(a * n + x, b * n + y, iter - 1);
			}
		}
	}

}
