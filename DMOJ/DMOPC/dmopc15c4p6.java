import java.util.Scanner;

public class DMOPC_2015_C4_P6 {

	static int[][] archives, covered;
	static int[] R;
	static int N, A, max;
	static boolean[] row, col;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();

		archives = new int[N][N];
		covered = new int[N][N];
		row = new boolean[N];
		col = new boolean[N];

		for (int i = 0; i < archives.length; i++) {
			for (int j = 0; j < archives.length; j++) {
				archives[i][j] = in.nextInt();
			}
		}

		A = in.nextInt();
		R = new int[A];
		for (int i = 0; i < R.length; i++) {
			R[i] = in.nextInt();
		}

		dfs(0);
		System.out.println(max);
	}

	private static void dfs(int depth) {
		if (depth == A) {
			int rooms = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (covered[i][j] != 0 && archives[i][j] == 1) {
						rooms++;
					}
				}
			}
			max = Math.max(max, rooms);
		} else {
			int range = R[depth];
			for (int i = range - 1; i <= N - range; i++) {
				for (int j = range - 1; j <= N - range; j++) {
					if (!row[i] && !col[j] && archives[i][j] == 1) {
						for (int k = i - range + 1; k < i + range; k++) {
							for (int l = j - range + 1; l < j + range; l++) {
								covered[k][l]++;
							}
						}

						row[i] = col[j] = true;
						dfs(depth + 1);
						row[i] = col[j] = false;

						for (int k = i - range + 1; k < i + range; k++) {
							for (int l = j - range + 1; l < j + range; l++) {
								covered[k][l]--;
							}
						}
					}
				}
			}
		}
	}

}
