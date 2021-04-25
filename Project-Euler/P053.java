package euler100;

public class P053 {

	public static void main(String[] args) {
		int count = 0;
		for (int n = 23; n <= 100; n++) {
			for (int k = 2; k < n / 2; k++) {
				if (binomial(n, k) > 1000000) {
					count += n - 2 * k + 1;
					break;
				}
			}
		}
		System.out.println(count);
	}

	public static int binomial(int n, int k) {
		if (k == 0) {
			return 1;
		} else if (k > n / 2) {
			return binomial(n, n - k);
		}
		return n * binomial(n - 1, k - 1) / k;
	}
}
