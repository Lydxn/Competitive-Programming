import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class P5 {

	static List<Integer>[] adj;
	static boolean[] visited;
	static int[] dist;
	static int len;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int N = in.nextInt();

			adj = new ArrayList[101];
			visited = new boolean[101];
			dist = new int[101];
			len = 0;

			for (int j = 1; j <= 100; j++) {
				adj[j] = new ArrayList<Integer>();
			}

			for (int j = 0; j < N; j++) {
				adj[in.nextInt()].add(in.nextInt());
			}

			dfs(1, 0);
			System.out.println(len + 1);
		}
	}

	private static void dfs(int s, int p) {
		visited[s] = true;
		dist[s] = dist[p] + 1;

		for (int n : adj[s]) {
			if (visited[n]) len = Math.max(len, dist[s] - dist[n]);
			else 			dfs(n, s);
		}
	}

}
