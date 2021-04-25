package DMOJ;
import java.util.Scanner;

public class P1_HSIUNG {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int A = in.nextInt();
		int B = in.nextInt();
		int C = in.nextInt();
		
		boolean[] dp = new boolean[C + 1];
		dp[0] = true;
		
		for (int i = 0; i < dp.length; i++) {
			if (dp[i]) {
				if (i + A <= C) {
					dp[i + A] = true;
				}
				
				if (i + B <= C) {
					dp[i + B] = true;
				}
			}
		}
		
		for (int i = dp.length - 1; i >= 0; i--) {
			if (dp[i]) {
				System.out.println(i);
				return;
			}
		}
	}

}
