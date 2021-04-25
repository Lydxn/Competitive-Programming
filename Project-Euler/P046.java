package euler100;
import java.util.ArrayList;

public class P046 {

	public static void main(String[] args) {
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for (int i = 2; i <= 10000; i++) {
			if (isPrime(i)) {
				primes.add(i);
			}
		}
		
		int i = 1;
        boolean done = false;   
        
        for (; !done; i += 2) {
            done = true;
            for (int p : primes) {
                if (isSquare2(i - p)) {
                    done = false;
                    break;
                }
            } 
        }
        System.out.println(i - 2);
	}
	
	private static boolean isPrime(int n) {
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
	
	private static boolean isSquare2(int n) {
		double prime2 = Math.sqrt(n / 2);
		return prime2 == (int) prime2;
	}

}
