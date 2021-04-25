package euler100;

public class P060 {
	
	public static void main(String[] args) {
		long t1 = System.nanoTime();
		int[] ESieve = ESieve(10000);
		
		int sum = Integer.MAX_VALUE;
		for (int a = 0; a < ESieve.length; a++) {
			int EA = ESieve[a];
			if (EA * 5 >= sum) {
				break;
			} 
			
			for (int b = a + 1; b < ESieve.length; b++) {
				int EB = ESieve[b];
				if ((EA + EB) * 4 >= sum) {
					break;
				} else if (!concat(EA, EB)) {
					continue;
				}
				
				for (int c = b + 1; c < ESieve.length; c++) {
					int EC = ESieve[c];
					if ((EA + EB + EC) * 3 >= sum) {
						break;
					} else if (!concat(EA, EC) || !concat(EB, EC)) {
						continue;
					}
					
					for (int d = c + 1; d < ESieve.length; d++) {
						int ED = ESieve[d];
						if ((EA + EB + EC + ED) * 2 >= sum) {
							break;
						} else if (!concat(EA, ED) || !concat(EB, ED) || !concat(EC, ED)) {
							continue;
						}
					
						for (int e = d + 1; e < ESieve.length; e++) {
							int EE = ESieve[e];
							if (EA + EB + EC + ED + EE >= sum) {
								break;
							} else if (concat(EA, EE) && concat(EB, EE) && concat(EC, EE) && concat(ED, EE) &&
								sum > EA + EB + EC + ED + EE) {
								sum = EA + EB + EC + ED + EE;
							}
						}
					}
				}
			}
		}
		long t2 = System.nanoTime();
		System.out.println(sum);
		System.out.println(t2 - t1);
	}

	private static boolean concat(int a, int b) {
		int aLen = (int) Math.log10(a) + 1;
		int bLen = (int) Math.log10(b) + 1;
		return isPrime(a * (int) Math.pow(10, bLen) + b) && isPrime(b * (int) Math.pow(10, aLen) + a);
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
		isPrime[2] = true;
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
	
	private static boolean isPrime(int n) { 
		if (n == 2) {
        	return true;
        } else if ((n & 1) == 0) {
        	return false;
        } else if (n < 9) {
        	return true;
        } else if (n % 3 == 0 || n % 5 == 0) {
        	return false;
        }
        
        int d = n - 1; 
        while ((d & 1) == 0) {
            d >>= 1; 
        }
        return !test(d, n);
	}
	
	private static boolean test(int a, int n) {
        int t = 0;
        int u = n - 1;
        while ((u & 1) == 0) {
            t++;
            u >>= 1;
        }

        long x1 = modExp(a, u, n);
        long x2;

        for (int i = 0; i < t; i++) {
            x2 = x1 * x1 % n;
            if ((x2 == 1) && (x1 != 1) && (x1 != (n - 1))) {
            	return true;
            }
            x1 = x2;
        }
        return x1 != 1;
    }
	
	private static long modExp(int a, int b, int n) {
        long d = 1;
        int k = 0;
        while ((b >> k) > 0) {
        	k++;
        }

        for (int i = k - 1; i >= 0; i--) {
            d = d * d % n;
            if (((b >> i) & 1) > 0) {
            	d = d * a % n;
            }
        }
        return d;
    }
	
}
