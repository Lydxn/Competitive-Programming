package DMOJ;
import java.util.Scanner;

public class Mr_Whites_Carnival {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		System.out.println(factorSum(N));
	}
	
	private static int factorSum(int N) {
		if (N == 0 || N == 1) {
			return N;
		}
		
		int res = 1 + N;
		for (int i = 2; i < Math.sqrt(N); i++) {
			if (N % i == 0) {
				res += i + N / i;
			}
		}
		
		double sqrt = Math.sqrt(N);
		if (sqrt == (int) sqrt) {
			res += sqrt;
		}
		return res;
	}

}