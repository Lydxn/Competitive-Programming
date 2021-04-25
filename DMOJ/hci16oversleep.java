package DMOJ;
import java.util.Scanner;

public class Oversleep {
	
	static int n, m;
	static int min = Integer.MAX_VALUE;
	static char[][] map;

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		in.nextLine();
		
		map = new char[n][m];
		for (int i = 0; i < map.length; i++) {
			map[i] = in.nextLine().toCharArray();
		}
		
		int sX = 0, sY = 0, eX = 0, eY = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 's') {
					sX = j;
					sY = i;
				} else if (map[i][j] == 'e') {
					eX = j;
					eY = i;
				}
			}
		}
		
		shortestPath(sX, sY, eX, eY, -1);
		System.out.println(min == Integer.MAX_VALUE ? -1 : min);
	}
	
	private static void shortestPath(int sX, int sY, int eX, int eY, int time) {
		if (sX == eX && sY == eY) {
			min = Math.min(min, time);
		} else if (sX >= 0 && sX < m && sY >= 0 && sY < n && map[sY][sX] != 'X') {
			map[sY][sX] = 'X';
			shortestPath(sX + 1, sY, eX, eY, time + 1);
			shortestPath(sX, sY + 1, eX, eY, time + 1);
			shortestPath(sX - 1, sY, eX, eY, time + 1);
			shortestPath(sX, sY - 1, eX, eY, time + 1);
			map[sY][sX] = '.';
		}
	}

}
