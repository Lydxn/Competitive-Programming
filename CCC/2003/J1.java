package ccc_2003;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter tine length:");
		int tineLength = in.nextInt();
		System.out.println("Enter tine spacing:");
		int tineSpacing = in.nextInt();
		System.out.println("Enter handle length:");
		int handleLength = in.nextInt();
		
		for (int i = 0; i < tineLength; i++) {
			System.out.print("*");
			for (int j = 0; j < tineSpacing; j++) {
				System.out.print(" ");
			}
			System.out.print("*");
			for (int j = 0; j < tineSpacing; j++) {
				System.out.print(" ");
			}
			System.out.println("*");
		}
		
		for (int i = 0; i < 2 * tineSpacing + 3; i++) {
			System.out.print("*");
		}
		System.out.println();
		
		for (int i = 0; i < handleLength; i++) {
			for (int j = 0; j < tineSpacing + 1; j++) {
				System.out.print(" ");
			}
			System.out.println("*");
		}
	}

}
