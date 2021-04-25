package DMOJ;
import java.util.Scanner;

public class Next_Prime {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		for (int i = N; ; i++) {
			if (isPrime(i)) {
				System.out.println(i);
				return;
			}
		}
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