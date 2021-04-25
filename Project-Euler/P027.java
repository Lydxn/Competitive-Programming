package euler100;

import java.util.ArrayList;

public class P027 {
	
	static ArrayList<Integer> primes = new ArrayList<Integer>();

	public static void main(String[] args) {
		primes();
		
		int max = 0;
		int maxAB = 0;
		
		for (int a = -999; a < 1000; a += 2) {
			for (int b : primes) {
				int c = consecPrimes(a, b);
				if (max < c) {
					max = c;
					maxAB = a * b;
				}
			}
		}
		System.out.println(maxAB);
	}
	
	private static void primes() {
		for (int i = 2; i <= 1000; i++) {
			boolean prime = true;
			for (int j = 2; j <= Math.sqrt(i); j++) {
				if (i % j == 0) {
					prime = false;
					break;
				}
			}
			
			if (prime) {
				primes.add(i);
			}
		}
	}
	
	private static boolean isPrime(int n) {
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
	
	private static int consecPrimes(int a, int b) {
		for (int n = 0; ; n++) {
			int quadratic = n * n + a * n + b;
			if (!isPrime(Math.abs(quadratic))) {
				return n;
			}
		}
	}
 
}
