package ccc_2015;
import java.util.Scanner;

public class J5 {
	
	static int[][][] cache = new int[251][251][251];
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		
		System.out.println(ways(n, k, 1));
	}
	
	private static int ways(int n, int k, int min) {
		if (k == n || k == 1) {
			return 1;
		} else if (cache[n][k][min] == 0) {
			for (int i = min; i <= n / k; i++) {
				cache[n][k][min] += ways(n - i, k - 1, i);
			}
		}
		return cache[n][k][min];
	}
	
}
