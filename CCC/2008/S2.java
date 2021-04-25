package ccc_2008;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			int n = in.nextInt();
			if (n == 0) {
				return;
			}
			System.out.println(pennies(n));
		}
	}
	
	private static int pennies(int n) {
		int count = 0;
		for (int i = 1; i < n; i++) {
			int y = (int) Math.sqrt(n * n - i * i);
			count += y;
		}
		return 4 * (count + n) + 1; 
	}

}
