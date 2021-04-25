package ccc_2011;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		char[] choices = new char[N * 2];
		for (int i = 0; i < N * 2; i++) {
			choices[i] = in.nextLine().charAt(0);
		}
		
		int C = 0;
		for (int j = 0; j < N; j++) {
			if (choices[j] == choices[j + N]) {
				C++;
			}
		}
		System.out.println(C);
	}

}
