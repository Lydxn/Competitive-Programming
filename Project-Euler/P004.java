package euler100;

public class P004 {

	public static void main(String[] args) {
		int max = 0;
		for (int i = 990; i >= 100; i -= 11) {
			for (int j = 999; j >= 100; j--) {
				int n = i * j;
				
				if (isPalin(n) && n > max) {
					max = n;
				}
			}
		}
		System.out.println(max);
	}

	private static boolean isPalin(int n) {
		int palin = n;
		int reverse = 0;
		
		while (n > 0) {
			reverse = reverse * 10 + n % 10;
			n /= 10;
		}
		return palin == reverse;
	}
	
}
