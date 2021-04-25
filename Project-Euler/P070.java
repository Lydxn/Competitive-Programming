package euler100;
import java.util.ArrayList;
import java.util.List;

public class P069 {

	public static void main(String[] args) {
		List<Integer> ESieve = ESieve(4000);

		double minRatio = Double.POSITIVE_INFINITY;
		int minN = 1;
		
		for (int i = 0; i < ESieve.size(); i++) {
			for (int j = i + 1; j < ESieve.size(); j++) {
				int n = ESieve.get(i) * ESieve.get(j);
				if (n > 10000000) {
					break;
				}
				
				int phi = (ESieve.get(i) - 1) * (ESieve.get(j) - 1);
				double ratio = (double) n / phi;
				
				if (isPerm(n, phi) && minRatio > ratio) {
					minRatio = ratio;
					minN = n;
				}
			}
		}
		System.out.println(minN);
	}
	
	private static List<Integer> ESieve(int lim) {
        boolean[] isPrime = new boolean[lim];
        for (int i = 0; i < lim; i++) {
        	isPrime[i] = true;
        }
        isPrime[0] = false;
        isPrime[1] = false;
        
        for (int i = 2; i * i <= lim; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < lim; j += i) {
                	isPrime[j] = false;
                }
            }
        }
        
        List<Integer> primes = new ArrayList<Integer>();
        for (int i = 0; i < isPrime.length; i++) {
        	if (isPrime[i]) {
        		primes.add(i);
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
		
		for (int d : digits) {
			if (d != 0) {
				return false;
			}
		}
		return true;
	}

}
