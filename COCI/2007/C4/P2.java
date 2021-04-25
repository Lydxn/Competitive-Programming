package COCI;
import java.util.Arrays;
import java.util.Scanner;

public class COCI_2007_C4_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int X = in.nextInt();
		
		char[] xDigits = new char[Integer.toString(X).length()];
		digits(X, xDigits);
		
		for (int j = X + 1; j < Math.pow(10, xDigits.length); j++) {
			char[] jDigits = new char[Integer.toString(j).length()];
			digits(j, jDigits);
			
			if (Arrays.equals(xDigits, jDigits)) {
				System.out.println(j);
				return;
			}
		}
		System.out.println(0);
	}
	
	public static void digits(int n, char[] arr) {
		String nStr = Integer.toString(n);
		
		for (int i = 0; i < arr.length; i++) {
			arr[i] = nStr.charAt(i);
		}
		Arrays.sort(arr);
	}

}