package AtCoder.DP;
import java.util.Scanner;

public class LCS {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();
		String t = in.nextLine();
		
		int[][] dp = new int[s.length() + 1][t.length() + 1];
		for (int i = 1; i <= s.length(); i++) {
			for (int j = 1; j <= t.length(); j++) {
				dp[i][j] = s.charAt(i - 1) == t.charAt(j - 1) ? dp[i - 1][j - 1] + 1 
															  : Math.max(dp[i - 1][j], dp[i][j - 1]);
				
			}
		}

		StringBuilder res = new StringBuilder();		
		for (int i = s.length(), j = t.length(); i > 0 && j > 0;) {
			if (s.charAt(i - 1) == t.charAt(j - 1)) {
				res.append(s.charAt(i - 1));
				i--;
				j--;
			} else if (dp[i - 1][j] > dp[i][j - 1]) {
				i--;
			} else {
				j--;
			}
		}
		System.out.println(res.reverse());
	}

}