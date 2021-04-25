package AtCoder.DP;
import java.util.Scanner;

public class Coins {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		double[] coins = new double[N + 1];
		for (int i = 1; i <= N; i++) {
			coins[i] = in.nextDouble();
		}
		
		double[][] dp = new double[N + 1][N + 1];
		dp[0][0] = 1;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				if (j > 0) dp[i][j] += dp[i - 1][j - 1] * coins[i];
				dp[i][j] += dp[i - 1][j] * (1 - coins[i]);
			}
		}
		
		double prob = 0;
		for (int i = N / 2 + 1; i <= N; i++) {
			prob += dp[N][i];
		}
		System.out.println(prob);
	}

}
