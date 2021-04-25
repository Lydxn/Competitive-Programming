import java.io.*;
import java.util.*;

public class Main {
    static int H, N;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());

		short[][] field = new short[N][N];
		for (int i = 0; i < field.length; i++) {
		    StringTokenizer f = new StringTokenizer(br.readLine());
			for (int j = 0; j < field.length; j++) {
				field[i][j] = Short.parseShort(f.nextToken());
			}
		}
		System.out.println(isCrossable(field, 0, 0) ? "yes" : "no");
	}

	private static boolean isCrossable(short[][] field, int x, int y) {
		if (x == N - 1 && y == N - 1) {
			return true;
		}

		boolean crossable = false;
		if (x >= 0 && x < N && y >= 0 && y < N && field[y][x] != -1) {
			short temp = field[y][x];
			field[y][x] = -1;

			if (x < N - 1 && Math.abs(field[y][x + 1] - temp) <= H) {
				crossable |= isCrossable(field, x + 1, y);
			}

			if (y < N - 1 && Math.abs(field[y + 1][x] - temp) <= H) {
				crossable |= isCrossable(field, x, y + 1);
			}

			if (x > 0 && Math.abs(field[y][x - 1] - temp) <= H) {
				crossable |= isCrossable(field, x - 1, y);
			}

			if (y > 0 && Math.abs(field[y - 1][x] - temp) <= H) {
				crossable |= isCrossable(field, x, y - 1);
			}
		}
		return crossable;
	}
}
