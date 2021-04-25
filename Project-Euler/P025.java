package euler100;
import java.math.BigInteger;

public class P025 {

	public static void main(String[] args) {
		for (int i = 12; ; i++) {
			if (fib(i).toString().length() == 1000) {
				System.out.println(i);
				return;
			}
		}
	}
	
	private static BigInteger fib(int n) {
		BigInteger a = BigInteger.ZERO;
		BigInteger b = BigInteger.ONE;
		BigInteger c;
		
		if (n == 0) {
			return a;
		}
		
		for (int i = 2; i <= n; i++) {
			c = a.add(b);
			a = b;
			b = c;
		}
		return b;
	}
}
