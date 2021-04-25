package euler100;

import java.util.Arrays;

public class P038 {

	public static void main(String[] args) {
		int n = 0;
		for (int i = 9487; i >= 9234; i--) {
			n = 100002 * i;
			if (isPandigital(Integer.toString(n))) {
				System.out.println(n);
				return;
			}
		}
	}
	
	private static boolean isPandigital(String digits) {
		char[] pandigits = digits.toCharArray();
		Arrays.sort(pandigits);
		return Arrays.equals(pandigits, "123456789".toCharArray());
	}

}
