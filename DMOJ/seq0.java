package DMOJ;
import java.io.*;
import java.util.StringTokenizer;

public class Summing_A_Sequence {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		long[] dp = new long[N + 2];
		StringTokenizer nums = new StringTokenizer(br.readLine());
		for (int i = 2;i <= N + 1; i++) {
			dp[i] = Math.max(dp[i - 1], dp[i - 2] + Integer.parseInt(nums.nextToken()));
		}
		System.out.println(dp[N + 1]);
	}

}
