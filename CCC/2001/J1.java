package ccc_2001;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter height:");
		int height = in.nextInt();
		System.out.println();
		
		int spaces = height * 2 - 2;
		int asterisk = 1;
		
		for (int i = 0; i < height; i++) {
			for (int a = 0; a < asterisk; a++) {
				System.out.print("*");
			}
			
			for (int s = 0; s < spaces; s++) {
				System.out.print(" ");
			}
			
			for (int a = 0; a < asterisk; a++) {
				System.out.print("*");
			}
			
			if (height / 2 > i) {
				spaces -= 4;
				asterisk += 2;
			} else {
				spaces += 4;
				asterisk -= 2;
			}
			System.out.println();
		}
	}

}
