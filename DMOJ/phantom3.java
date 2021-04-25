package DMOJ;
import java.util.*;

public class The_Torture_Chamber {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long N = in.nextLong();
		long M = in.nextLong();
		System.out.println(segmentedESieve(N, M));
	}
	
	private static List<Integer> ESieve(int lim) {
		List<Integer> primes = new ArrayList<Integer>();
		BitSet bits = new BitSet(lim + 1);
		bits.set(2, lim);
     
        for (int i = 2; i < lim; i++) {
            if (bits.get(i)) {
            	primes.add(i);
                for (int j = 2 * i; j < lim; j += i) {
                	bits.clear(j);
                }
            }
        }
        return primes;
    }
	
	private static int segmentedESieve(long low, long high) {
		List<Integer> primes = ESieve((int) Math.ceil(Math.sqrt(high)));
		boolean[] check = new boolean[(int) (high - low)];
		
		for (long p : primes) {
			long lowLim = low / p * p;
			if (lowLim < low) {
				lowLim += p;
			} 

			for (long j = lowLim; j < high; j += p) {
				check[(int) (j - low)] = true;
			}
			
			if (p >= low && p < high) {
				check[(int) (p - low)] = false;
			}
		}
		
		int res = 0;
		for (long i = (low & 1) == 0 ? low + 1: low; i < high; i += 2) {
			if (!check[(int) (i - low)]) {
				res++;
			}
		}
		return res;
	}

}