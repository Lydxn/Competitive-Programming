package AtCoder.DP;
import java.util.Arrays;
import java.util.Scanner;

public class Frog_2 {

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		
		int[] heights = new int[N + K];
		for (int i = 1; i <= N; i++) {
			heights[i] = in.nextInt();
		}
		
		int[] dp = new int[N + K];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[1] = 0;
		
		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= K; j++) {
				dp[i + j] = Math.min(dp[i + j], dp[i] + Math.abs(heights[i] - heights[i + j]));
			}
		}
		System.out.println(dp[N]);
	}

}