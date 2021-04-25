package euler100;
import java.math.BigInteger;

public class P056 {

	public static void main(String[] args) {
		int sum = 0;
		for (int a = 99; a >= 95; a--) {
			for (int b = 99; b > 0; b--) {
				BigInteger pow = BigInteger.valueOf(a).pow(b);		
				if (pow.toString().length() * 9 < sum) {
					break;
				}
				
				int digSum = digSum(pow);
				if (sum < digSum) {
					sum = digSum;
				}
			}
		}
		System.out.println(sum);
	}
	
	private static int digSum(BigInteger n) {
		String digits = n.toString();
		int sum = 0;
		for (int i = 0; i < digits.length(); i++) {
			sum += Character.getNumericValue(digits.charAt(i));
		}
		return sum;
	}

}
