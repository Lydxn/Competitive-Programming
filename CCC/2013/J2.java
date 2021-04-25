package ccc_2013;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String bothWays = in.nextLine();

		for (int i = 0; i < bothWays.length(); i++) {
			if ("IOSHZN".indexOf(bothWays.charAt(i)) == -1) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}

}
