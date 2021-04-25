package euler100;

public class P058 {

	public static void main(String[] args) {
		int primes = 8;
		int diagonals = 13;
		for (int i = 9; ; i += 2) {
			primes += gridPrimes(i);
			diagonals += 4;
			
			if ((double) primes / diagonals < 0.1) {
				System.out.println(i);
				return;
			}
		}
	}
	
	private static int gridPrimes(int grid) {
		int primes = 0;
		for (int i = 0; i < 4; i++) {
			if (isPrime(grid * grid - i * grid + i)) {
				primes++;
			}
		}
		return primes;
	}
	
	private static boolean isPrime(int n) {
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

}
