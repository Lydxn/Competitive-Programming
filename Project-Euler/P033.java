package euler100;

public class P033 {

	public static void main(String[] args) {
		int den = 1;
		int num = 1;
		
		for (int i = 1; i < 10; i++) {
			for (int d = 1; d < i; d++) {
				for (int n = 1; n < d; n++) {
					if ((10 * n + i) * d == (10 * i + d) * n) {
						den *= d;
						num *= n;
					}
				}
			}
		}
		System.out.println(den /= gcf(den, num));
	}
	
	private static int gcf(int a, int b) {
		int x = 0;
		int y = 0;
		
		if (a > b) {
			x = a;
			y = b;
		} else {
			x = b;
			y = a;
		}
		
		while (x % y != 0) {
			int temp = x;
			x = y;
			y = temp % x;
		}
		return y;
	}

}
