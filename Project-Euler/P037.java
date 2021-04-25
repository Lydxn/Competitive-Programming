package euler100;

public class P037 {

	public static void main(String[] args) {
		int count = 0;
		int sum = 0;
		for (int i = 11; count < 11; i++) {
			if (isPrime(i) && isTruncatable(i)) {
				sum += i;
				count++;
			}
		}
		System.out.println(sum);
	}

	private static boolean isTruncatable(int n) {
		int fromLeft = n % (int) Math.pow(10, (int) Math.log10(n));
		int fromRight = n / 10;
		while (fromRight > 0) {
			if (!isPrime(fromLeft) || !isPrime(fromRight)) {
				return false;
			}
		
			fromLeft %= (int) Math.pow(10, (int) Math.log10(fromLeft));
			fromRight /= 10;
		}
		return true;
	}
	
	private static boolean isPrime(int n) {
		if (n == 1) {
			return false;
		}
		
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
	
}
