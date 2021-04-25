package euler100;
import java.math.BigInteger;

public class P016 {

	public static void main(String[] args) {
		BigInteger pow = BigInteger.ONE;
		for (int j = 0; j < 1000; j++) {
			pow = pow.multiply(BigInteger.TWO);
		}

		int sum = 0;
		String powStr = pow.toString();
		for (int j = 0; j < powStr.length(); j++) {
			sum += Character.getNumericValue(powStr.charAt(j));
		}
		System.out.println(sum);
		
	}

}
