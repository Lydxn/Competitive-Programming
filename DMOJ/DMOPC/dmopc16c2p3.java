import java.util.Scanner;

public class DMOPC_2016_C2_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			int M = in.nextInt();

			int maxX = 0, maxY = 0;
			for (int j = 0; j < M; j++) {
				maxX = Math.max(maxX, in.nextInt());
				maxY = Math.max(maxY, in.nextInt());
			}

			if (maxX + maxY > N) {
				System.out.println(-1);
			} else {
				for (int j = 0; j < maxX; j++) System.out.print('a');
				for (int j = 0; j < N - maxX; j++) System.out.print('b');
				System.out.println();
			}
		}
	}

}
