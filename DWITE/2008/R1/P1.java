import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int[] heights = new int[5];
		String[] hills = new String[5];

		for (int i = 0; i < 5; i++) {
			heights[i] = in.nextInt();
			hills[i] = "";
		}

		for (int h : heights) {
			for (int i = 0; i < 5; i++) {
				if (h == 0) {
					hills[i] += ".";
				} else {
					int width = h * 2 - 1;
					int mid = Math.max(width - i * 2, 0);
					int side = (width - mid) / 2;

					hills[5 - i - 1] += fill(".", side) + fill("x", mid) + (mid > 0 ? "" : ".") + fill(".", side);
				}
			}
		}

		for (String h : hills) {
			System.out.println(h);
		}
	}

	public static String fill(String str, int n) {
		return String.join("", Collections.nCopies(n, str));
	}
}
