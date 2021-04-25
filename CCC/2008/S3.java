package ccc_2008;
import java.util.Arrays;
import java.util.Scanner;

public class S3 {
	
	static char[][] city;
	static int[][] steps;
	static int r, c;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			r = in.nextInt();
			c = in.nextInt();
			in.nextLine();
			
			city = new char[r][];
			for (int j = 0; j < city.length; j++) {
				city[j] = in.nextLine().toCharArray();
			}
			
			steps = new int[r][c];
			for (int j = 0; j < r; j++) {
				Arrays.fill(steps[j], Integer.MAX_VALUE);
			}
			
			shortestPath(0, 0, 1);
			int end = steps[r - 1][c - 1];
			System.out.println(end >= 0 && end < Integer.MAX_VALUE ? end : -1);
		}
	}
	
	private static void shortestPath(int x, int y, int path) {
		if (x >= 0 && x < c && y >= 0 && y < r && path < steps[y][x]) {
			switch (city[y][x]) {
			case '+':
				steps[y][x] = path;
				shortestPath(x + 1, y, path + 1);
				shortestPath(x - 1, y, path + 1);
				shortestPath(x, y + 1, path + 1);
				shortestPath(x, y - 1, path + 1);
				break;
			case '-':
				steps[y][x] = path;
				shortestPath(x + 1, y, path + 1);
				shortestPath(x - 1, y, path + 1);
				break;
			case '|':
				steps[y][x] = path;
				shortestPath(x, y + 1, path + 1);
				shortestPath(x, y - 1, path + 1);
				break;
			default:
				steps[y][x] = -1;
			}
		}
	}

}
