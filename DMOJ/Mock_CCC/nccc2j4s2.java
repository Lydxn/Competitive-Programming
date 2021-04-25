import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);

		int[][] rects = new int[3][2];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				rects[i][j] = in.nextInt();
			}
		}

		double sqrtArea = Math.sqrt(rects[0][0] * rects[0][1] + rects[1][0] * rects[1][1] + rects[2][0] * rects[2][1]);
		if (Math.floor(sqrtArea) - sqrtArea != 0) {
			System.out.println("NO");
			return;
		}

		int index = 0;
		int width = 0;
		outer: for (int k = 0; k < 3; k++) {
			for (int l = 0; l < 2; l++) {
				if (rects[k][l] == sqrtArea) {
					index = k;
					width = rects[k][(l + 1) % 2];
					break outer;
				}
			}
		}

		if ((rects[(index + 2) % 3][0] + rects[(index + 1) % 3][0] == sqrtArea &&
			 rects[(index + 2) % 3][1] == rects[(index + 1) % 3][1] && rects[(index + 1) % 3][1] == sqrtArea - width) ||

			(rects[(index + 2) % 3][0] + rects[(index + 1) % 3][1] == sqrtArea &&
			 rects[(index + 2) % 3][1] == rects[(index + 1) % 3][0] && rects[(index + 1) % 3][0] == sqrtArea - width) ||

			(rects[(index + 2) % 3][1] + rects[(index + 1) % 3][0] == sqrtArea &&
			 rects[(index + 2) % 3][0] == rects[(index + 1) % 3][1] && rects[(index + 1) % 3][1] == sqrtArea - width) ||

			(rects[(index + 2) % 3][1] + rects[(index + 1) % 3][1] == sqrtArea &&
			 rects[(index + 2) % 3][0] == rects[(index + 1) % 3][0] && rects[(index + 1) % 3][0] == sqrtArea - width)) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
    }
}
