package euler100;
import java.math.BigInteger;

public class P057 {

	public static void main(String[] args) {
		
		BigInteger num = BigInteger.valueOf(1393);
		BigInteger den = BigInteger.valueOf(985);
		int more = 1;
		
		for (int i = 9; i <= 1000; i++) {
			num = num.add(BigInteger.TWO.multiply(den));
			den = num.subtract(den);
			
			if (num.toString().length() > den.toString().length()) {
				more++;
			}
		}
		System.out.println(more);
	}

}
