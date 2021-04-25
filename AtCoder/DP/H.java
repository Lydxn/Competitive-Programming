package AtCoder.DP;
import java.util.Scanner;

public class Grid_1 {

	static int MOD = 1000000007;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int H = in.nextInt();
		int W = in.nextInt();
		in.nextLine();
		
		char[][] grid = new char[H][W];
		long[][] dp = new long[H][W];
		
		for (int i = 0; i < H; i++) {
			grid[i] = in.nextLine().toCharArray();
		}
		
		dp[0][0] = 1;
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				if (grid[h][w] == '.') {
					if (h > 0) {
						dp[h][w] += dp[h - 1][w] % MOD;
					}
					
					if (w > 0) {
						dp[h][w] += dp[h][w - 1] % MOD;
					}
				}
			}
		}
		System.out.println(dp[H - 1][W - 1] % MOD);
	}

}