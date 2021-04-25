package DMOJ;
import java.util.Scanner;

public class Pick_It {
	
	static int[] arr;
	static int[][] cache;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			int n = in.nextInt();
			if (n == 0) {
				return;
			}
			
			arr = new int[n];
			cache = new int[n + 1][n + 1];
			
			for (int i = 0; i < n; i++) {
				arr[i] = in.nextInt();
			}
			System.out.println(maxScore(0, n - 1));
		}
	}

	private static int maxScore(int left, int right) {
		if (left == right) {
			return 0;
		} else if (cache[left][right] != 0) {
			return cache[left][right];
		} else {
			int max = 0;
			for (int i = left + 1; i < right; i++) {
				max = Math.max(max, maxScore(left, i) + maxScore(i, right) + arr[left] + arr[i] + arr[right]); 
			}
			return cache[left][right] = max;
		}
	}
	
}