package euler100;
import java.util.Arrays;

public class P049 {

	public static void main(String[] args) {
		int[] ESieve = ESieve(1489, 10000);
		for (int i = 0; i < ESieve.length; i++) {
			for (int j = i + 1; j < ESieve.length; j++) {
				int k = 2 * ESieve[j] - ESieve[i];
				if (k < 10000 && Arrays.binarySearch(ESieve, k) >= 0 && isPerm(ESieve[i], k) && isPerm(ESieve[j], k)) {
					System.out.println(100000000L * (ESieve[i]) + 10000 * ESieve[j] + k);
					return;
				}
			}
		}
	}
	
	public static int[] ESieve(int low, int high) { 
		boolean[] isPrime = new boolean[high];
		for (int i = 3; i < high; i += 2) {
			isPrime[i] = true;
		}
		
		for (int i = 3; i * i < high; i += 2) {
			if (isPrime[i]) {
				for (int j = i * 2; j < high; j += i) {
					isPrime[j] = false;
				}
			}
		}

		int count = 0;
		for (int i = low; i < high; i++) {
			if (isPrime[i]) {
				count++;
			}
		}
		
		int[] primes = new int[count];
		for (int i = low, j = 0; i < high; i++) {
			if (isPrime[i]) {
				primes[j] = i;
				j++;
			}
		}
		return primes;
	}
	
	private static boolean isPerm(int a, int b) {
		int[] digits = new int[10];
		
		while (a != 0) {
			digits[a % 10]++;
			a /= 10;
		}
		
		while (b != 0) {
			digits[b % 10]--;
			b /= 10;
		}
		
		for (int i : digits) {
			if (i != 0) {
				return false;
			}
		}
		return true;
	}

}
