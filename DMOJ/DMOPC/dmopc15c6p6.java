import java.util.BitSet;
import java.util.Scanner;

public class DMOPC_2015_C6_P6 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		int K = in.nextInt();

		BitSet[] adj = new BitSet[N];
		for (int i = 0; i < adj.length; i++) {
			adj[i] = new BitSet(N);
		}

		for (int i = 0; i < M; i++) {
			int e1 = in.nextInt() - 1;
			int e2 = in.nextInt() - 1;

			adj[e1].set(e2);
			adj[e2].set(e1);
		}

		for (int i = 0; i < N; i++) {
			BitSet bs = new BitSet(N), temp = new BitSet(N);
			bs.set(i);

			for (int j = 0; j < K; j++) {
				temp = (BitSet) bs.clone();
				for (int k = 0; k < N; k++) {
					if (temp.get(k)) {
						bs.or(adj[k]);
					}
				}
			}
			System.out.println(bs.cardinality());
		}
	}

}
