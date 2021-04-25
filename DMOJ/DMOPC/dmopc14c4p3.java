import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer size = new StringTokenizer(br.readLine());
		int L = Integer.parseInt(size.nextToken());
		int D = Integer.parseInt(size.nextToken());

		byte[][] ground = new byte[D][L];
		for (int i = 0; i < D; i++) {
		    StringTokenizer line = new StringTokenizer(br.readLine());
			for (int j = 0; j < L; j++) {
				ground[i][j] = Byte.parseByte(line.nextToken());
			}
		}

		StringTokenizer gold = new StringTokenizer(br.readLine());
		int goldX = Integer.parseInt(gold.nextToken());
		int goldY = Integer.parseInt(gold.nextToken());
		System.out.println(minCost(ground, L, D, goldX, goldY));
	}

	private static int minCost(byte[][] ground, int sX, int sY, int eX, int eY) {
		int[][] dp = new int[sY][sX];
		dp[0][0] = ground[0][0];

		for (int i = 1; i < sY; i++) {
			dp[i][0] = dp[i - 1][0] + ground[i][0];
		}

		for (int i = 1; i < sX; i++) {
			dp[0][i] = dp[0][i - 1] + ground[0][i];
		}

		for (int i = 1; i < sY; i++) {
			for (int j = 1; j < sX; j++) {
				dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + ground[i][j];
			}

			for (int j = sX - 2; j >= 0; j--) {
				dp[i][j] = Math.min(dp[i][j], dp[i][j + 1] + ground[i][j]);
			}
		}
		return dp[eY][eX];
	}
}
