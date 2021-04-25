package euler100;
import java.util.ArrayList;
import java.util.List;

public class P069 {

	public static void main(String[] args) {
		List<Integer> ESieve = ESieve(1000000);
		
		int res = 1;
		for (int i = 0; res * ESieve.get(i) < 1000000; i++) {
			res *= ESieve.get(i);
		}
		System.out.println(res);
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

}
