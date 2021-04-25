package DMOJ;
import java.util.Scanner;

public class Math_Depression {
	
	static int MOD = 1000000007;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		long maxSadness = 0;
		switch (N % 3) {
		case 0:
			maxSadness = powMod(3, N / 3) % MOD;
			break;
		case 1:
			maxSadness = 4 * powMod(3, N / 3 - 1) % MOD;
			break;
		case 2:
			maxSadness = 2 * powMod(3, N / 3) % MOD;
			break;
		}
		
		System.out.println(maxSadness);
	}
	
	private static long powMod(long base, long exponent) {
		long res = 1;
		while (exponent > 0) {
			if ((exponent & 1) == 1) {
				res = (res * base) % MOD;
			}
			
			base = (base * base) % MOD;
			exponent >>= 1;
		}
		return res;
	}

}