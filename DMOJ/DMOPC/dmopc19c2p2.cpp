import java.util.Scanner;

public class DMOPC_2019_C2_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();

		int[][] grid = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				grid[i][j] = in.nextInt();
			}
		}

		System.out.println(minCost(grid, N, M));
	}

	private static long minCost(int[][] grid, int N, int M) {
		long[][] dp = new long[N][M];

		dp[0][0] = grid[0][0];
		for (int i = 1; i < N; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
		for (int j = 1; j < M; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];

		for (int i = 1; i < N; i++) {
			for (int j = 1; j < M; j++) {
				dp[i][j] = (long) Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[N - 1][M - 1];
	}

}
