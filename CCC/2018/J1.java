package ccc_2018;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();

		if ((a == 8 || a == 9) && (d == 8 || d == 9) && b == c) {
			System.out.println("ignore");
		} else {
			System.out.println("answer");
		}
	}

}
