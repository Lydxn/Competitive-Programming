package euler100;

public class P051 {
	
	static int[][] replace = {{3, 4, 5, 0, 1, 2}, {2, 4, 5, 0, 1, 3}, {2, 3, 5, 0, 1, 4}, {1, 4, 5, 0, 2, 3}, {1, 3, 5, 0, 2, 4}, 
							  {1, 2, 5, 0, 3, 4}, {0, 4, 5, 1, 2, 3}, {0, 3, 5, 1, 2, 4}, {0, 2, 5, 1, 3, 4}, {0, 1, 5, 2, 3, 4}};
	static boolean[] ESieve = ESieve(1000000);

	public static void main(String[] args) {
		for (int i = 101; i < 1000; i += 2) {
			for (int j = 0; j < replace.length; j++) {
				int[] digits = new int[6];
				int temp = i;
				
				for (int k = 2; k >= 0; k--) {
					digits[replace[j][k]] = temp % 10;
					temp /= 10;
				}
				
				if (prime8(digits, j)) {
					System.out.println(toNum(digits));
					return;
				}
			}
		}
	}
	
	private static boolean prime8(int[] digits, int part) {
		int[] temp = digits;
		int count = 0;
		
		for (int j = 9; j >= (replace[part][3] == 0 ? 1 : 0); j--) {
			for (int k = 3; k < 6; k++) {
				temp[replace[part][k]] = j;
			}

			if (ESieve[toNum(temp)] && (int) Math.log10(toNum(temp)) + 1 == 6) {
				count++;
			}
		}
		return count == 8;
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

	private static int toNum(int[] n) {
		StringBuilder str = new StringBuilder();
		for (int i : n) {
			str.append(i);
		}
		return Integer.parseInt(str.toString());
	}
	
}

