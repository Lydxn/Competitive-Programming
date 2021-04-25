package ccc_2007;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();

		for (int i = 0; i < n; i++) {
			int y = in.nextInt();
			int m = in.nextInt();
			int d = in.nextInt();
			
			System.out.println(((y < 1989) || (y == 1989 && m < 2) || (y == 1989 && m == 2 && d <= 27)) ? "Yes" : "No");
		}
	}

}
