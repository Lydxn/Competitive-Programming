package DMOJ;
import java.math.BigInteger;
import java.util.Scanner;

public class PalinDrone {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger N = in.nextBigInteger();

		BigInteger MOD = BigInteger.valueOf(1000000000);
		BigInteger res;

		if (N.compareTo(BigInteger.valueOf(17)) == 1) {
			res = BigInteger.valueOf(1000000000);
		} else if (N.and(BigInteger.ONE).equals(BigInteger.ZERO)) {
			res = BigInteger.TWO.multiply(BigInteger.TEN.modPow(N.add(BigInteger.ONE).shiftRight(1), MOD));
		} else {
			res = BigInteger.TEN.modPow(N.add(BigInteger.ONE).shiftRight(1), MOD).add(
				  BigInteger.TEN.modPow(N.subtract(BigInteger.ONE).shiftRight(1), MOD));
		}
		System.out.println(res.subtract(BigInteger.TWO).mod(MOD));
	}

}