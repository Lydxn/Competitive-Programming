import java.util.*;
import java.io.*;

public class DMOPC_2013_C1_P4 {

	static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
		    StringTokenizer dim = new StringTokenizer(br.readLine());
			int l = Integer.parseInt(dim.nextToken());
			int w = Integer.parseInt(dim.nextToken());

			char[][] home = new char[w][l];
			for (int j = 0; j < home.length; j++) {
				home[j] = br.readLine().toCharArray();
			}

			int sx = 0, sy = 0;
			for (int j = 0; j < w; j++) {
				for (int k = 0; k < l; k++) {
					if (home[j][k] == 'C') {
						sx = k;
						sy = j;
					}
				}
			}

			int shortestPath = bfs(home, sx, sy);
			System.out.println(shortestPath >= 60 || shortestPath == -1 ? "#notworth" : shortestPath);
		}
	}

	private static int bfs(char[][] home, int sx, int sy) {
		int w = home.length, l = home[0].length;
		Queue<int[]> queue = new ArrayDeque<int[]>();
		boolean[][] visited = new boolean[w][l];
		int[][] dist = new int[w][l];

		queue.add(new int[] {sx, sy});
		visited[sy][sx] = true;
		for (int i = 0; i < dist.length; i++) Arrays.fill(dist[i], Integer.MAX_VALUE);
		dist[sy][sx] = 0;

		while (!queue.isEmpty()) {
			int[] curr = queue.poll();
			int cx = curr[0], cy = curr[1];

			if (home[cy][cx] == 'W') {
				return dist[cy][cx];
			}

			for (int[] d : dir) {
				int nx = cx + d[0], ny = cy + d[1];
				if (nx >= 0 && nx < l && ny >= 0 && ny < w && home[ny][nx] != 'X' && !visited[ny][nx]) {
					visited[ny][nx] = true;
					queue.add(new int[] {nx, ny});
					dist[ny][nx] = dist[cy][cx] + 1;
				}
			}
		}
		return -1;
	}

}
