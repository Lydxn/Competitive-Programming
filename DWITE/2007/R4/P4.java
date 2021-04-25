import java.io.*;
import java.util.*;

public class P4 {

    static class Node {
		int x;
		int y;
		int dist;

		Node(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.dist = dist;
		}
	}

	static int[][] dir = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		char[][] maze = new char[10][10];
		outer: for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 10; j++) {
				maze[j] = in.nextLine().toCharArray();
			}
			in.nextLine();

			for (int x = 0; x < 10; x++) {
				for (int y = 0; y < 10; y++) {
					if (maze[y][x] == 'X') {
						System.out.println(shortestPath(maze, x, y));
						continue outer;
					}
				}
			}
		}
	}

	private static int shortestPath(char[][] maze, int x, int y) {
		Queue<Node> queue = new ArrayDeque<Node>();
		boolean[][] visited = new boolean[10][10];

		maze[y][x] = '#';
		visited[y][x] = true;
		queue.offer(new Node(x, y, 0));

		while (!queue.isEmpty()) {
			Node curr = queue.poll();
			if (maze[curr.y][curr.x] == 'X') {
				return curr.dist;
			}

			for (int[] d : dir) {
				int nx = curr.x + d[0];
				int ny = curr.y + d[1];

				if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && !visited[ny][nx] && maze[ny][nx] != '#') {
					visited[ny][nx] = true;
					queue.offer(new Node(nx, ny, curr.dist + 1));
				}
			}
		}
		return -1;
	}

}
