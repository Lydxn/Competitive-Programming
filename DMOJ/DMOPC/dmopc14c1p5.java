import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DMOPC_2014_C1_P5 {

	static class Pair {
		int r, c;
		public Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int R = in.nextInt();
		int C = in.nextInt();
		Pair start = new Pair(in.nextInt(), in.nextInt());
		Pair end = new Pair(in.nextInt(), in.nextInt());
		in.nextLine();

		char[][] grid = new char[R][C];
		for (int i = 0; i < grid.length; i++) {
			grid[i] = in.nextLine().toCharArray();
		}

		boolean[][] isDevice = new boolean[R][C];
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int tr = in.nextInt(), tc = in.nextInt();
			isDevice[tr][tc] = true;
		}

		Queue<Pair> queue = new ArrayDeque<Pair>();
		int[][] dist = new int[R][C];
		boolean[][] visited = new boolean[R][C];

		queue.add(start);
		visited[start.r][start.c] = true;
		dist[start.r][start.c] = 0;

		int minDist = Integer.MAX_VALUE;
		while (!queue.isEmpty()) {
			Pair curr = queue.poll();
			if (curr.r == end.r && curr.c == end.c) break;

			for (int[] d : dir) {
				int nr = curr.r + d[0], nc = curr.c + d[1];
				if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 'O' && !visited[nr][nc]) {
					visited[nr][nc] = true;
					queue.add(new Pair(nr, nc));
					dist[nr][nc] = dist[curr.r][curr.c] + 1;

					if (isDevice[nr][nc]) {
						minDist = Math.min(minDist, dist[nr][nc]);
					}
				}
			}
		}
		System.out.println(minDist == Integer.MAX_VALUE ? 2 : dist[end.r][end.c] - minDist);
	}

}
