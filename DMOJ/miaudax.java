package DMOJ;
import java.util.Arrays;
import java.util.Scanner;

public class Multiplication_Improvement {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char[] digits = in.nextLine().replace("x", "").toCharArray();
		
		long prod = 1;
		for (char c : digits) {
			prod *= c - '0';
		}
		Arrays.sort(digits);
		
		System.out.println(String.copyValueOf(digits).replace("", "x").substring(1, digits.length * 2));
		System.out.println(prod);
	}

}