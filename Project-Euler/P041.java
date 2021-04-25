package euler100;

public class P041 {

	public static void main(String[] args) {
		for (int i = 7654321; ; i--) {
			if (isPrime(i) && isPandigital(i)) {
				System.out.println(i);
				return;
			}
		}
	}
	
	private static boolean isPandigital(int n) {
		int digits = 0;
		int count = 0;
		for (; n > 0; n /= 10, count++) {
        	if (digits == (digits |= 1 << (n - n / 10 * 10 - 1))) {
        		return false;
        	}
        }

        return digits == (1 << count) - 1;
	}
	
	private static boolean isPrime(int n) {
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
	
}
