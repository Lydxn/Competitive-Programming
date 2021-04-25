package AtCoder.DP;
import java.util.Arrays;
import java.util.Scanner;

public class Frog_1 {

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[] heights = new int[N + 2];
		for (int i = 1; i <= N; i++) {
			heights[i] = in.nextInt();
		}
		
		int[] dp = new int[N + 2];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[1] = 0;
		
		for (int i = 1; i < N; i++) {
			dp[i + 1] = Math.min(dp[i + 1], dp[i] + Math.abs(heights[i] - heights[i + 1]));
			dp[i + 2] = Math.min(dp[i + 2], dp[i] + Math.abs(heights[i] - heights[i + 2]));
		}
		System.out.println(dp[N]);
	}

}