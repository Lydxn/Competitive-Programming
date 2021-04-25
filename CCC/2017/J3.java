package ccc_2017;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		int t = in.nextInt();
		
		int dist = Math.abs((d - b)) + Math.abs((c - a));
		
		if (t < dist) {
			System.out.println('N');
		} else {
			if (dist % 2 == 0 && t % 2 == 0) {
				System.out.println('Y');
			} else if (dist % 2 == 0 && t % 2 == 1) {
				System.out.println('N');
			} else if (dist % 2 == 1 && t % 2 == 0) {
				System.out.println('N');
			} else {
				System.out.println('Y');
			}
		}
	}

}
