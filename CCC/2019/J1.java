package ccc_2019;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a3 = in.nextInt();
		int a2 = in.nextInt();
		int a1 = in.nextInt();
		int b3 = in.nextInt();
		int b2 = in.nextInt();
		int b1 = in.nextInt();
		
		int apples = a3 * 3 + a2 * 2 + a1;
		int bananas = b3 * 3 + b2 * 2 + b1;
		System.out.println(apples > bananas ? 'A' : (apples < bananas ? 'B' : 'T'));
	}

}
