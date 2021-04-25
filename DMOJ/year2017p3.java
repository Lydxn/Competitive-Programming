package DMOJ;
import java.io.*;
import java.util.StringTokenizer;

public class Fibonacci_Presents {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int k = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		
		int[] coolness = new int[n + 1];
		for (int i = 0; i < n; i++) {
			coolness[i] = Integer.parseInt(br.readLine());
		}
		
		long[] dp = new long[n + 1];
		dp[0] = coolness[0];
		dp[1] = Math.max(dp[0], coolness[1]);
		
		for (int i = 2; i <= n; i++) {
			dp[i] = Math.max(coolness[i], coolness[i - 1] + dp[i - 2]);
		}
		
		System.out.println(k <= 2 ? Math.max(dp[0], dp[1]) : 
						  (k > n + 1 ? -1 :
						   dp[k - 1]));
	}

}