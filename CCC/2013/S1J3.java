package ccc_2013;
import java.util.Scanner;

public class S1_J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int Y = in.nextInt();

		Y++;
		while (!distinct(Y)) {
			Y++;
		}
		System.out.println(Y);
	}
	
	private static boolean distinct(int year) {
		int[] digits = new int[10];
		
		while (year > 0) {
			digits[year % 10]++;
			year /= 10;
		}
		
		for (int i = 0; i < 10; i++){
			if (digits[i] > 1) {
				return false;
			}
		}
		return true;
	}

}
