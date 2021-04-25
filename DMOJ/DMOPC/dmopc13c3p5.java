import java.util.Scanner;

public class DMOPC_2013_C3_P5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int M = in.nextInt();
		int U = in.nextInt();
		int R = in.nextInt();

		int[][] knapsack = new int[R + 1][3];
		for (int i = 1; i <= R; i++) {
			for (int j = 0; j < 3; j++) {
				knapsack[i][j] = in.nextInt();
			}
		}

		int[][][] dp = new int[R + 1][M + 1][U + 1];
		for (int r = 1; r <= R; r++) {
			for (int m = 1; m <= M; m++) {
				for (int u = 1; u <= U; u++) {
					dp[r][m][u] = knapsack[r][1] > m || knapsack[r][2] > u
							? dp[r - 1][m][u] :
							  Math.max(dp[r - 1][m][u], knapsack[r][0] + dp[r - 1][m - knapsack[r][1]][u - knapsack[r][2]]);

				}
			}
		}
		System.out.println(dp[R][M][U]);
	}

}
