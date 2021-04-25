package AtCoder.DP;
import java.util.Arrays;
import java.util.Scanner;

public class Vacation {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[][] dp = new int[N + 1][3];
		for (int i = 1; i <= N; i++) {
			int[] activities = new int[3];
			for (int j = 0; j < activities.length; j++) {
				activities[j] = in.nextInt();
			}
			
			for (int j = 0; j < activities.length; j++) {
				dp[i][j] = Math.max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + activities[j];
			}
		}
		System.out.println(Arrays.stream(dp[N]).max().getAsInt());
	}
	
}