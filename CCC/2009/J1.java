package ccc_2009;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Digit 11? ");
		int a = in.nextInt();
		System.out.print("Digit 12? ");
		int b = in.nextInt();
		System.out.print("Digit 13? ");
		int c = in.nextInt();
		
		System.out.println("The 1-3-sum is " + (91 + a + (b * 3) + c));
	}

}
