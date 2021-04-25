import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();

		int[][] bonds = new int[n][n];
		for (int i = 0; i < m; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;

			bonds[a][b]++;
			bonds[b][a]++;
		}

		int[] numBonds = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				numBonds[i] += bonds[i][j];
			}

			if (numBonds[i] != 1 && numBonds[i] != 4) {
				System.out.println("Impossible");
				return;
			}
		}

		int x = 0;
		int y = 0;
		int energy = 0;
		boolean[] visited = new boolean[n];

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				if (numBonds[i] == 4) {
					x++;
				}

				if (numBonds[i] == 1) {
					y++;
				}

				for (int j = 0; j < n; j++) {
					if (!visited[j] && bonds[i][j] > 0) {
						visited[i] = true;
						energy += ((numBonds[i] == 4 && numBonds[j] == 1) || (numBonds[i] == 1 && numBonds[j] == 4) && bonds[i][j] == 1 ? 413 :
								  	numBonds[i] == 4 && numBonds[j] == 4 && bonds[i][j] == 1										    ? 346 :
									numBonds[i] == 4 && numBonds[j] == 4 && bonds[i][j] == 2 											? 615 :
																																		  0);
					}
				}
			}
		}

		System.out.println(energy);
		System.out.println("C" + (x == 1 ? "" : x) + "H" + (y == 1 ? "" : y));
	}
}
