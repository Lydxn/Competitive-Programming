package ccc_1997;
import java.math.BigInteger;
import java.util.Scanner;

public class P5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < n; i++) {
			BigInteger dividend = new BigInteger(in.nextLine());
			BigInteger divisor = new BigInteger(in.nextLine());
			System.out.println(dividend.divide(divisor));
			System.out.println(dividend.mod(divisor) + "\n");
		}
	}

}
