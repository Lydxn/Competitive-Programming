package ccc_2001;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter x:");
		int x = in.nextInt();
		System.out.println("Enter m:");
		int m = in.nextInt();
		
		int n = 1;
		while (!(n >= m || x * n % m == 1)) {
			n++;
		}
		System.out.println("\n" + (n < m ? n : "No such integer exists."));
	}

}
