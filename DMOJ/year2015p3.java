package DMOJ;
import java.util.Scanner;

public class Gift_Wrap {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		char[][] gift = new char[2 * N - 1][2 * N - 1];
		for (int i = 0; i < gift.length; i++) {
			
		}
		
		for (char[] i : gift) {
			for (char j : i) {
				System.out.print(j);
			}
			System.out.println();
		}
	}

}