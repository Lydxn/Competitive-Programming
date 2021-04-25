package euler100;
import java.util.Arrays;
import java.util.HashSet;

public class P032 {
	
	static HashSet<Integer> products = new HashSet<Integer>();

	public static void main(String[] args) {
		panRange(1, 9, 1234, 9876);
		panRange(12, 98, 123, 987);
		System.out.println(products.stream().mapToInt(Integer::intValue).sum());
	}
	
	private static boolean isPandigital(String digits) {
		char[] pandigits = digits.toCharArray();
		Arrays.sort(pandigits);
		return Arrays.equals(pandigits, "123456789".toCharArray());
	}
	
	private static void panRange(int aS, int aE, int bS, int bE) {
		for (int a = aS; a <= aE; a++) {
			for (int b = bS; b <= bE; b++) {
				int ab = a * b;
				String digits = "" + a + b + ab;
				if (isPandigital(digits)) {
					products.add(ab);
				}
			}
		}
	}
	
}
