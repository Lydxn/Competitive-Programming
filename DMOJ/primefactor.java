package DMOJ;
import java.util.Scanner;

public class Prime_Factorization {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		for (int i = 0; i < N; i++) {
			int M = in.nextInt();
			primeFactors(M);
		}
	}
	
	private static void primeFactors(int M) {
		StringBuilder res = new StringBuilder();
		while ((M & 1) == 0) {
			res.append(2).append(" ");
			M >>= 1;
		}
		
		for (int i = 3; i <= Math.sqrt(M); i += 2) {
			while (M % i == 0) {
				res.append(i).append(" ");
				M /= i;
			}
		}
		
		if (M > 2) {
			res.append(M);
		}
		System.out.println(res.toString().trim());
	}

}