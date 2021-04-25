package DMOJ;
import java.util.Scanner;

public class The_Mirror {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		for (int i = 0; i < N; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			
			int count = 0;
			for (int j = a; j < b; j++) {
				if (isPrime(j)) {
					count++;
				}
			}
			System.out.println(count);
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