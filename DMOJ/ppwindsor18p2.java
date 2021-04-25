package DMOJ;

import java.util.Scanner;

public class Big_Chess {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int W = in.nextInt();
		int H = in.nextInt();

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				System.out.print((i + j) % 2 == 0 ? 0 : 1);
			}
			System.out.println();
		}
	}

}
