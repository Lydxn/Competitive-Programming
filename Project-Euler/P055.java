package euler100;
import java.math.BigInteger;

public class P055 {

	public static void main(String[] args) {
		long a = System.nanoTime();
		int lychrel = 0;
		for (int i = 10; i < 10000; i++) {
			if (isLychrel(i)) {
				lychrel++;
			}
		}
		long b = System.nanoTime();
		System.out.println(lychrel);
		System.out.println(b - a);
	}
	
	private static boolean isLychrel(int n) {
		BigInteger bigN = BigInteger.valueOf(n);
		for (int i = 0; i < 50; i++) {
			bigN = bigN.add(reverse(bigN));
			if (isPalin(bigN)) {
				return false;
			}
		}
		return true;
	}
	
	private static boolean isPalin(BigInteger n) {
		String nStr = String.valueOf(n);
		return nStr.equals(new StringBuilder(nStr).reverse().toString());
	}
	
	private static BigInteger reverse(BigInteger n) {
		return new BigInteger(new StringBuilder().append(n).reverse().toString());
	}
	
}
