package DMOJ;

import java.util.Scanner;

public class The_Third_Cellar {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		boolean[] ESieve = ESieve(1000000);
		for (int i = 0; i < N; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			
			int count = 0;
			for (int j = a; j < b; j++) {
				if (ESieve[j]) {
					count++;
				}
			}
			System.out.println(count);
		}
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