package DMOJ;
import java.io.*;

public class Next_Semiprime {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int Q = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < Q; i++) {
			int N = Integer.parseInt(br.readLine());
			
			for (int j = N + 1; ; j++) {
				if (semiPrime(j)) {
					System.out.println(j);
					break;
				}
			}
		}
	}
	
	private static boolean semiPrime(int N) {
		if (isPrime(N)) {
			return false;
		}
		
		int factor;
		do {
			factor = brent(N);
		} while (factor == N);
		return isPrime(factor) && isPrime(N / factor);
	}
	
	private static int brent(int N) {
		if (N % 2 == 0) {
			return 2;
		} else {
			long Y, C, M, G, R, Q, YS, X;
			Y = C = M = (long) (Math.random() * (N - 2) + 1);
			G = R = Q = 1;
			YS = X = 0;
			
			while (G == 1) {
				X = Y;
				for (int i = 0; i < R; i++) {
					Y = (Y * Y % N + C) % N;
				}
				
				int K = 0;
				while (K < R && G == 1) {
					YS = Y;
					for (int i = 0; i < Math.min(M, R - K); i++) {
						Y = (Y * Y % N + C) % N;
						Q = Q * Math.abs(X - Y) % N;
					}
					
					G = gcd(Q, N);
					K += M;
				}
				R <<= 1;
			}
			
			if (G == N) {
				while (G <= 1) {
					YS = (YS * YS % N + C) % N;
					G = gcd(Math.abs(X - YS), N);
				}
			}
			return (int) G;
		}
	}
	
	private static boolean isPrime(int N) {
	    if (N == 2 || N == 3) {return true;}
	    if ((N & 1) == 0 || N % 3 == 0 || N == 1) {return false;}

	    for (int i = 5; i * i <= N; i += 6) {
	        if (N % i == 0 || N % (i + 2) == 0) {
	        	return false;
	        }
	    }
	    return true;
	}
	
	private static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
}
