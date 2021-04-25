package euler100;
import java.math.BigInteger;
import java.util.HashSet;

public class P029 {

	public static void main(String[] args) {
		HashSet<BigInteger> powers = new HashSet<BigInteger>();
		for (int a = 2; a <= 100; a++) {
			BigInteger bigA = BigInteger.valueOf(a);
			for (int b = 2; b <= 100; b++) {
				powers.add(bigA.pow(b));
			}
		}
		System.out.println(powers.size());
	}

}
