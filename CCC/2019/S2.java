package ccc_2019;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			
			for (int A = N, B = N; A >= 2; A--, B++) {
				if (isPrime(A) && isPrime(B)) {
					System.out.println(A + " " + B);
					break;
				}
			}
		}
	}
	
	private static boolean isPrime(int N) {
		for (int i = 2; i <= Math.sqrt(N); i++) {
			if (N % i == 0) {
				return false;
			}
		}
		return true;
	}

}
