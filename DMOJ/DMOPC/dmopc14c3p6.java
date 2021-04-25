import java.util.Scanner;

public class DMOPC_2014_C3_P6 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int T = in.nextInt();

		int[][] P = new int[N + 1][3];
		int[][] V = new int[N + 1][3];
		for (int i = 1; i <= N; i++) {
			P[i][0] = in.nextInt();
			V[i][0] = in.nextInt();
			P[i][1] = in.nextInt();
			V[i][1] = in.nextInt();
			P[i][2] = in.nextInt();
			V[i][2] = in.nextInt();
		}

		int[] dp = new int[T + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = T; j >= 0; j--) {
				for (int k = 0; k < 3; k++) {
					if (P[i][k] <= j) {
						dp[j] = Math.max(dp[j], V[i][k] + dp[j - P[i][k]]);
					}
				}
			}
		}
		System.out.println(dp[T]);
	}

}
