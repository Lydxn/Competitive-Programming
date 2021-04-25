package euler100;
import java.math.BigInteger;

public class P066 {

	public static void main(String[] args) {
		BigInteger maxPell = BigInteger.ZERO;
		int maxD = 0;
		
		for (int D = 2; D <= 1000; D++) {
			BigInteger pell = pell(BigInteger.valueOf(D));
			if (pell.compareTo(maxPell) == 1 && !pell.equals(BigInteger.valueOf(-1))) {
				maxPell = pell;
				maxD = D;
			}
		}
		System.out.println(maxD);
	}
	
	private static BigInteger pell(BigInteger D) {
		BigInteger a0 = D.sqrt();
		if (a0.pow(2).equals(D)) {
			return BigInteger.ONE.negate();
		}
		
		BigInteger m = BigInteger.ZERO;
		BigInteger d = BigInteger.ONE;
		BigInteger a = a0;
		
		BigInteger numM1 = BigInteger.ONE;
		BigInteger num = a;
		BigInteger denM1 = BigInteger.ZERO;
		BigInteger den = BigInteger.ONE;

		while (!num.pow(2).subtract(D.multiply(den.pow(2))).equals(BigInteger.ONE)) {
			m = d.multiply(a).subtract(m);
			d = D.subtract(m.pow(2)).divide(d);
			a = a0.add(m).divide(d);
			
			BigInteger numM2 = numM1;
			BigInteger denM2 = denM1;
			numM1 = num;
			denM1 = den;
			
			num = a.multiply(numM1).add(numM2);
			den = a.multiply(denM1).add(denM2);
		}
		return num;
	}
	
}
