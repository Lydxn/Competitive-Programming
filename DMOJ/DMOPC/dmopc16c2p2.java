import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class dmopc16c2p2 {

	static int[] ds;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();

		ds = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			ds[i] = i;
		}

		for (int i = 0; i < M; i++) {
			int K = in.nextInt();
			int A = in.nextInt();

			for (int j = 1; j < K; j++) {
				union(A, in.nextInt());
			}
		}

		List<Integer> res = new ArrayList<Integer>();
		int find1 = find(1);

		for (int i = 1; i <= N; i++) {
			if (find(i) == find1) {
				res.add(i);
			}
		}

		System.out.println(res.size());
		for (int r : res) System.out.print(r + " ");
		System.out.println();
	}

	private static int find(int x) {
		if (ds[x] != x) ds[x] = find(ds[x]);
		return ds[x];
	}

	private static void union(int x, int y) {
		ds[find(x)] = find(y);
	}

}
