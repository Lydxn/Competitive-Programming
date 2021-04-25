package euler100;

public class P021 {

	public static void main(String[] args) {
		int sum = 0;
		for (int i = 1; i < 10000; i++) {
			int a = d(i);
			int b = d(a);
			if (a != b && i == b) {
				sum += a + b;
			}
		}
		System.out.println(sum / 2);
	}

	private static int d(int n) {
		int sum = 1;
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				sum += i + n / i;
				if (n * n == i) {
					sum -= i;
				}
			}
		}
		return sum;
	}
	
}
