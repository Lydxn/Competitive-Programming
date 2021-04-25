package euler100;
import java.math.BigInteger;

public class P020 {

	public static void main(String[] args) {
		BigInteger factorial = BigInteger.ONE;
		for (BigInteger i = BigInteger.TWO; i.compareTo(BigInteger.valueOf(100)) < 0; i = i.add(BigInteger.ONE)) {
			factorial = factorial.multiply(i);
		}
		
		String factorialStr = factorial.toString();
		int sum = 0;
		for (int j = 0; j < factorialStr.length(); j++) {
			sum += Character.getNumericValue(factorialStr.charAt(j));
		}
		System.out.println(sum);
	}

}
