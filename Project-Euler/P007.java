package euler100;

public class P007 {

	public static void main(String[] args) {
		int primes = 0; 
		for (long i = 2; ; i++) {
			if (isPrime(i)) {
				primes++;
				if (primes == 10001) {
					System.out.println(i);
					return;
				}
			}
		}
	}
	
	private static boolean isPrime(long n) {
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
	
}
