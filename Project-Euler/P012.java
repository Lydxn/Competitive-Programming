package euler100;

public class P012 {

	public static void main(String[] args) {
		int tri = 1;
		for (int i = 1; ; i += tri) {
			if (divisors(i) > 500) {
				System.out.println(i);
				return;
			}
			tri++;
		}
	}
	
	private static int divisors(int n) {
		int exp = 0; 
		int factors = 1;
		
		while (n % 2 == 0) {
			exp++;
			n /= 2;
		}
		factors *= exp + 1;

		int N = n;
		for (int i = 3; i <= Math.sqrt(N); i++) {
			exp = 0;
			while (n % i == 0) {
				exp++;
				n /= i;
			}
			factors *= exp + 1;
		}
		return factors;
	}
	
}

