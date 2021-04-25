package euler100;
import java.util.ArrayList;

public class P050 {

	public static void main(String[] args) {
		boolean[] ESieve = ESieve(1000000);
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for (int i = 0; i < ESieve.length; i++) {
			if (ESieve[i]) {
				primes.add(i);
			}
		}

		int maxSum = 0;
		int maxCount = 0;
		for (int i = 0; i < primes.size(); i++) {
			int sum = 0;
			int count = 0;
			for (int j = i; j < primes.size(); j++) {
				sum += primes.get(j);
				if (sum >= 1000000) {
					break;
				}
				
				if (ESieve[sum] && count > maxCount) {
					maxCount = count;
					maxSum = sum;
				}
				count++;
			}
		}
		System.out.println(maxSum);
	}
	
	private static boolean[] ESieve(int lim) {
        boolean[] primes = new boolean[lim];
        for (int i = 0; i < lim; i++) {
            primes[i] = true;
        }
        primes[0] = false;
        primes[1] = false;
        
        for (int i = 2; i * i < lim; i++) {
            if (primes[i]) {
                for (int j = i * i; j < lim; j += i) {
                	primes[j] = false;
                }
            }
        }
        return primes;
    }

}

