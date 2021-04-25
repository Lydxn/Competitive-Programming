package euler100;

public class P052 {

	public static void main(String[] args) {
		for (int i = 10; ; i *= 10) {
			main: for (int j = i; j < i * 10 / 6; j++) {
				for (int k = 2; k <= 6; k++) {
					if (!isPerm(j, j * k)) {
						continue main;
					}
				}
				
				System.out.println(j);
				return;
			}
		}
	}
	
	private static boolean isPerm(int a, int b) {
		int[] digits = new int[10];
		
		while (a != 0) {
			digits[a % 10]++;
			a /= 10;
		}
		
		while (b != 0) {
			digits[b % 10]--;
			b /= 10;
		}
		
		for (int i : digits) {
			if (i != 0) {
				return false;
			}
		}
		return true;
	}

}
