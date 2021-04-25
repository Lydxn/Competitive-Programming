package DMOJ;
import java.util.Scanner;

public class Productive_Math_Class {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		long digits = 9;
		int len = 1;
		int first = 1;
		
		while (N > len * digits) {
			N -= len * digits;
			len++;
			first *= 10;
			digits *= 10;
		}
		first += (N - 1) / len;
		
		System.out.println(Character.getNumericValue(Integer.toString(first).charAt((N - 1) % len)));
	}

}
