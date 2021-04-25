package euler100;

public class P047 {

	static int[] ESieve = ESieve(1000);
	
	public static void main(String[] args) {
		int consec = 0;
		int i = 2 * 3 * 5 * 7;
		for (; consec < 4; i++) {
			consec = distinctFactors(i) == 4 ? consec + 1 : 0;
		}
		System.out.println(i - 4);
	}
	
	private static int[] ESieve(int lim) { 
		boolean[] isPrime = new boolean[lim];
		for (int i = 3; i < lim; i += 2) {
			isPrime[i] = true;
		}
		
		isPrime[2] = true;
		for (int i = 3; i * i < lim; i += 2) {
			if (isPrime[i]) {
				for (int j = i * 2; j < lim; j += i) {
					isPrime[j] = false;
				}
			}
		}

		int count = 0;
		for (int i = 1; i < lim; i++) {
			if (isPrime[i]) {
				count++;
			}
		}
		
		int[] primes = new int[count];
		for (int i = 1, j = 0; i < lim; i++) {
			if (isPrime[i]) {
				primes[j] = i;
				j++;
			}
		}
		return primes;
	}
	
	private static int distinctFactors(int n) {
		int count = 0;
		for (int i : ESieve) {
			boolean divisible = false;
			while (n % i == 0) {
				if (!divisible) {
					count++;
				}
				
				n /= i;
				divisible = true;
			}
		}
		return count;
	}
	
}
