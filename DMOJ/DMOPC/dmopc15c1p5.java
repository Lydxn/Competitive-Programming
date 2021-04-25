import java.io.*;
import java.util.*;

public class Main {

    static int[][] prefix;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int W = in.nextInt();
		int H = in.nextInt();
		int N = in.nextInt();

		prefix = new int[H + 1][W + 1];
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				prefix[i][j] += in.nextInt() + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
			}
		}

		int res = 0;
		for (int s = 1; s <= N; s++) {
			int w = s - 1;
			int h = N / s - 1;

			for (int i = 1; i <= H - h; i++) {
				for (int j = 1; j <= W - w; j++) {
					res = Math.max(res, sum(i, j, i + h, j + w));
				}
			}
		}
		System.out.println(res);
	}

	private static int sum(int a, int b, int c, int d) {
		return prefix[c][d] - prefix[a - 1][d] - prefix[c][b - 1] + prefix[a - 1][b - 1];
	}
}
