import java.util.Scanner;

public class dmopc16c1p3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] p = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			p[i] = in.nextInt();
		}

		double[] dp = new double[N + 1];
		for (int i = 1; i <= N; i++) {
			dp[i] = p[i] + dp[i - 1];
			if (i > 1) dp[i] = Math.min(dp[i], p[i] + p[i - 1] + dp[i - 2] - Math.min(p[i], p[i - 1]) / 2.0);
			if (i > 2) dp[i] = Math.min(dp[i], p[i] + p[i - 1] + p[i - 2] + dp[i - 3] - Math.min(p[i], Math.min(p[i - 1], p[i - 2])));
		}
		System.out.printf("%.1f\n", dp[N]);
	}

}
