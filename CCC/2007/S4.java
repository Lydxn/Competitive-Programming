package ccc_2007;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class S4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		@SuppressWarnings("unchecked")
		List<Integer>[] paths = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) {
			paths[i] = new ArrayList<Integer>();
		}
		
		while (true) {
			int x = in.nextInt();
			int y = in.nextInt();
			if (x == 0 && y == 0) {
				break;
			}
			
			paths[y].add(x);
		}
		
		int[] dp = new int[n + 1];
		dp[1] = 1;
		
		for (int i = 2; i <= n; i++) {
			for (int p : paths[i]) {
				dp[i] += dp[p];
			}
		}
		System.out.println(dp[n]);
	}

}
