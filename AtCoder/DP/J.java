package AtCoder.DP;
import java.util.Scanner;

public class Sushi {

	static double[][][] dp = new double[301][301][301];
	static int N;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		
		int[] freq = new int[4];
		for (int i = 0; i < N; i++) {
			freq[in.nextInt()]++;
		}
		System.out.println(dfs(freq[1], freq[2], freq[3]));
	}
	
	private static double dfs(int a, int b, int c) {
		if (a == 0 && b == 0 && c == 0) return 0;
		else if (dp[a][b][c] > 0) return dp[a][b][c];
		else {
			double res = (double) N / (a + b + c);
			if (a > 0) res += (double) a / (a + b + c) * dfs(a - 1, b, c);
			if (b > 0) res += (double) b / (a + b + c) * dfs(a + 1, b - 1, c);
			if (c > 0) res += (double) c / (a + b + c) * dfs(a, b + 1, c - 1);
			return dp[a][b][c] = res;
		}
	}

}
