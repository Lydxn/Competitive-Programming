import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DMOPC_2015_C3_P3 {

	static List<Integer>[] adj;
	static boolean[] visited;
	static int[] cycles;
	static boolean cyclic6;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();

		adj = new ArrayList[N];
		for (int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Integer>();
		}

		for (int i = 0; i < M; i++) {
			adj[in.nextInt() - 1].add(in.nextInt() - 1);
		}

		visited = new boolean[N];
		cycles = new int[N];

		for (int i = 0; i < adj.length; i++) {
			if (!visited[i]) {
				findCycle(i, 0);
			}
		}
		System.out.println(cyclic6 ? "YES" : "NO");
	}

	private static void findCycle(int node, int depth) {
		visited[node] = true;
		cycles[node] = depth;

		for (int a : adj[node]) {
			if (cycles[a] != -1 && depth - cycles[a] == 5) cyclic6 = true;
			if (!visited[a]) findCycle(a, depth + 1);
		}
	}

}
