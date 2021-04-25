package DMOJ;
import java.math.BigInteger;
import java.util.Scanner;

public class Fibonacci_Sequence {

	static BigInteger[] res = {BigInteger.ZERO, BigInteger.ZERO};
	static BigInteger a, b, c, d;
	static final BigInteger MOD = BigInteger.valueOf(1000000007);

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger N = new BigInteger(in.nextLine());
		
		fib(N);
		System.out.println(res[0]);
	}
	
	private static void fib(BigInteger N) {
		if (N.equals(BigInteger.ZERO)) {
			res[1] = BigInteger.ONE;
			return;
		} else {
			fib(N.shiftRight(1));
			
			a = res[0];
			b = res[1];
			c = (a.multiply(b.shiftLeft(1).subtract(a))).mod(MOD);
			d = a.pow(2).add(b.pow(2)).mod(MOD);
			
			boolean even = N.and(BigInteger.ONE).equals(BigInteger.ZERO);
			res[0] = even ? c : d;
			res[1] = even ? d : c.add(d);
		}
 	}

}
