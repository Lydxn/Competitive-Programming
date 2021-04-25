package AtCoder.DP;
import java.util.Scanner;

public class Knapsack_1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int W = in.nextInt();
		
		long[] dp = new long[W + 1];
		for (int i = 1; i <= N; i++) {
			int w = in.nextInt();
			int v = in.nextInt();
			
			for (int j = W; j >= w; j--) {
				dp[j] = Math.max(dp[j], dp[j - w] + v);
			}
		}
		System.out.println(dp[W]);
	}
}