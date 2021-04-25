package AtCoder.DP;
import java.util.Arrays;
import java.util.Scanner;

public class Knapsack_2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int W = in.nextInt();
		
		long[] dp = new long[1000 * N + 1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		
		for (int i = 0; i < N; i++) {
			int w = in.nextInt();
			int v = in.nextInt();
			
			for (int j = dp.length - 1; j >= v; j--) {
				dp[j] = Math.min(dp[j], dp[j - v] + w);
			}
		}
		
		for (int i = dp.length - 1; i >= 0; i--) {
			if (dp[i] <= W) {
				System.out.println(i);
				return;
			}
		}
	}

}