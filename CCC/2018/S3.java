import java.util.*;

public class S3 {

	static char[][] factory;
	static Queue<int[]> queue = new ArrayDeque<int[]>();
	static boolean[][] invalid;
	static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, dist;
	static int N, M;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		M = in.nextInt();
		in.nextLine();
		
		factory = new char[N][M];
		for (int i = 0; i < N; i++) {
			factory[i] = in.nextLine().toCharArray();
		}
		
		int sx = 0;
		int sy = 0;
		
		invalid = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (factory[i][j] == 'W') {
					invalid[i][j] = true;
				} else if (factory[i][j] == 'C') {
					checkCam(factory, j, i);
				} else if (factory[i][j] == 'S') {
					sx = j;
					sy = i;
				}
			}
		}
		
		dist = new int[N][M];
		for (int i = 0; i < dist.length; i++) {
			Arrays.fill(dist[i], Integer.MAX_VALUE);
		}
		
		minSteps(sx, sy);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (factory[i][j] == '.') {
					System.out.println(dist[i][j] == Integer.MAX_VALUE ? -1 : dist[i][j]);
				}
			}
		}
		
	}
	
	private static void minSteps(int sx, int sy) {
		if (invalid[sy][sx]) return;
		
		queue.add(new int[] {sx, sy});
		dist[sy][sx] = 0;
		
		while (!queue.isEmpty()) {
			int[] curr = queue.poll();
			int x = curr[0], y = curr[1];
			
			switch (factory[y][x]) {
			case '.': case 'S':
				for (int[] d : dir) {
					int nx = x + d[0], ny = y + d[1];
					enqueue(nx, ny, dist[y][x] + 1);
				}
				break;
			case 'L':
				enqueue(x - 1, y, dist[y][x]);
				break;
			case 'R':
				enqueue(x + 1, y, dist[y][x]);
				break;
			case 'U':
				enqueue(x, y - 1, dist[y][x]);
				break;
			case 'D':
				enqueue(x, y + 1, dist[y][x]);
				break;
			}
		}
	}
	
	private static void checkCam(char[][] factory, int x, int y) {
		invalid[y][x] = true;
		for (int[] d : dir) {
			for (int i = 1; ; i++) {
				int nextX = x + d[0] * i;
				int nextY = y + d[1] * i;
				
				if (factory[nextY][nextX] == '.' || factory[nextY][nextX] == 'S') {
					invalid[nextY][nextX] = true;
				} else if (factory[nextY][nextX] == 'W') {
					break;
				}
			}
		}
	}
	
	private static void enqueue(int x, int y, int incr) {
		if (!invalid[y][x] && dist[y][x] > incr) {
			dist[y][x] = incr;
			queue.add(new int[] {x, y});
		}
	}

}
