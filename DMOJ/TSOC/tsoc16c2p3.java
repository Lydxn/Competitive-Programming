package DMOJ;
import java.util.Scanner;

public class Lu_Han_And_Birthday {
	
	static int MOD = 2016420;

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		int A = in.nextInt();
		int B = in.nextInt();
		int C = in.nextInt();
		int D = in.nextInt();

		int sum = 0;
		for (int i = A; i <= B; i++) {
			if (isPrime(i)) {
				sum = (sum + multSum(C, D, i)) % MOD;
			}
		}
		System.out.println(sum);
	}
	
	private static int multSum(int low, int high, int mult) {
		long sum = 0;
		for (int i = (int) Math.ceil((double) low / mult); i <= high / mult; i++) {
			sum = (sum + i) % MOD;
		}
		return (int) (sum * mult % MOD);
	}
	
	private static boolean isPrime(int n) {
	    if (n == 2 || n == 3) {return true;}
	    if ((n & 1) == 0 || n % 3 == 0 || n == 1) {return false;}

	    for (int i = 5; i <= Math.sqrt(n); i += 6) {
	        if (n % i == 0 || n % (i + 2) == 0) {
	        	return false;
	        }
	    }
	    return true;
	}

}