package ccc_2012;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		
		if (a < b && b < c && c < d) {
			System.out.println("Fish Rising");
		} else if (a > b && b > c && c > d) {
			System.out.println("Fish Diving");
		} else if (a == b && b == c && c == d) {
			System.out.println("Fish At Constant Depth");
		} else {
			System.out.println("No Fish");
		}
	}

}
