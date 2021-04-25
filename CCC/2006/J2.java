package ccc_2006;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter m: ");
		int m = in.nextInt();
		System.out.print("Enter n: ");
		int n = in.nextInt();
		
		int count = 0;
		for (int i = 1; i <= n && i < 10; i++) {
			if (10 - i <= m && 10 - i != 0) {
				count++;
			}
		}

		System.out.println("There " + (count == 1 ? "is 1 way" : "are " + count + " ways ") + "to get the sum 10.");
	}

}
