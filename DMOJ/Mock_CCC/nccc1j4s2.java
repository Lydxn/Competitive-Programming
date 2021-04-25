import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();

		String[] rows = new String[N];
		int[][] latin = new int[N][N];

		for (int i = 0; i < N; i++) {
			rows[i] = in.nextLine();
			for (int j = 0; j < N; j++) {
				latin[i][j] = Character.isLetter(rows[i].charAt(j)) ? rows[i].charAt(j) - 55 : Integer.parseInt(rows[i].substring(j, j + 1));
			}
		}

		for (int k = 0; k < N; k++) {
			for (int l = 0; l < N; l++) {
				int next = latin[k][l];
				for (int m = l + 1; m < N; m++) {
					if (next == latin[k][m]) {
						System.out.println("No");
						return;
					}
				}
			}
		}

		for (int k = 0; k < N - 1; k++) {
			if (latin[0][k] > latin[0][k + 1] || latin[k][0] > latin[k + 1][0]) {
				System.out.println("Latin");
				return;
			}
		}
		System.out.println("Reduced");
    }
}
