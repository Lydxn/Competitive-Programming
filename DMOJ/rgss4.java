package DMOJ;
import java.util.Scanner;

public class P4_HEIGHT {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[] arr = new int[N];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = in.nextInt();
		}
		
		int[] dp = arr.clone();
		for (int i = 1; i < dp.length; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[i] < dp[j] + arr[i] && arr[j] < arr[i]) {
					dp[i] = dp[j] + arr[i];
				}
			}
		}
		
		int max = 0;
		for (int d : dp) {
			max = Math.max(max, d);
		}
		System.out.println(max);
	}
	
}
