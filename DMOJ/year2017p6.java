package DMOJ;
import java.util.Arrays;
import java.util.Scanner;

public class Christmas_Cards {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[] c = new int[N];
		int[] d = new int[N];
		for (int i = 0; i < N; i++) {
			c[i] = in.nextInt();
			d[i] = in.nextInt();
		}
		
		long[] dp = new long[N];
		Arrays.fill(dp, Long.MAX_VALUE - 1000000000);
		dp[0] = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = dp.length - 1; j >= i; j--) {
				int next = Math.min(j + d[i],  N - 1);
				dp[next] = Math.min(dp[next], dp[j] + c[i]);
			}
		}
		System.out.println(dp[N - 1]);
	}

}