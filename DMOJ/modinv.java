package DMOJ;
import java.math.BigInteger;
import java.util.Scanner;

public class Modular_Multiplicative_Inverse {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger N = in.nextBigInteger();
		BigInteger M = in.nextBigInteger();
		System.out.println(N.modInverse(M));
	}

}
