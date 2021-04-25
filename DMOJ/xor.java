package DMOJ;
import java.util.Scanner;

public class XOR {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int S = in.nextInt();
			int F = in.nextInt();
			System.out.println(rangeXOR(S, F));
		}
	}

	private static int rangeXOR(int S, int F) {
		return f(F) ^ f(S - 1);
	}
	
	private static int f(int n) {
		int[] pattern = {n, 1, n + 1, 0};
		return pattern[n & 3];
	}
	
}