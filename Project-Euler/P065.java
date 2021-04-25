package euler100;
import java.math.BigInteger;

public class P065 {

	public static void main(String[] args) {
		BigInteger n0 = BigInteger.ONE;
		BigInteger n1 = BigInteger.TWO;
		
		for (int i = 2; i <= 100; i++) {
			BigInteger temp = n0;
			int conv = i % 3 == 0 ? (i / 3) << 1 : 1;
			n0 = n1;		
			n1 = BigInteger.valueOf(conv).multiply(n0).add(temp);
		}
		System.out.println(digSum(n1));
	}
	
	private static int digSum(BigInteger n) {
		int sum = 0;
		while (!n.equals(BigInteger.ZERO)) {
			sum = sum + n.mod(BigInteger.valueOf(10)).intValue();
			n = n.divide(BigInteger.valueOf(10));
		}
		return sum;
	}

}
