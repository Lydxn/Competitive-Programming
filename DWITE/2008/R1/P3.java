import java.io.*;
import java.util.*;

public class P3 {

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

	static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		char[][] room = new char[10][19];
		int[][] points = new int[12][2];

		for (int i = 0; i < room.length; i++) {
			room[i] = in.nextLine().toCharArray();
			for (int j = 0; j < room[i].length; j++) {
				if (Character.isLetter(room[i][j])) {
					points[room[i][j] - 'A'][0] = i;
					points[room[i][j] - 'A'][1] = j;
				}
			}
		}

		for (int i = 0; i < 5; i++) {
			String schedule = in.nextLine();

			int res = 0;
			for (int j = 0; j < schedule.length() - 1; j++) {
				char ch = schedule.charAt(j);
				res += shortestPath(room, points[ch - 'A'][1], points[ch - 'A'][0], schedule.charAt(j + 1));
			}
			System.out.println(res);
		}
	}

	private static int shortestPath(char[][] room, int x, int y, char end) {
		Queue<Node> queue = new ArrayDeque<Node>();
		boolean[][] visited = new boolean[10][19];

		visited[y][x] = true;
		queue.offer(new Node(x, y, 0));

		while (!queue.isEmpty()) {
			Node curr = queue.poll();
			if (room[curr.y][curr.x] == end) {
				return curr.dist;
			}

			for (int[] d : dir) {
				int nx = curr.x + d[0];
				int ny = curr.y + d[1];

				if (nx >= 0 && nx < 19 && ny >= 0 && ny < 10 && !visited[ny][nx] && room[ny][nx] != '#') {
					visited[ny][nx] = true;
					queue.offer(new Node(nx, ny, curr.dist + 1));
				}
			}
		}
		return -1;
	}

}
