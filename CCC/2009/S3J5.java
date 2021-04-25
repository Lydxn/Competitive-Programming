package ccc_2009;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class S3_J5 {
	
	static boolean[][] ships = new boolean[50][50];
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		ship(1, 6, true);
		ship(2, 6, true);
		ship(3, 4, true);
		ship(3, 5, true);
		ship(3, 6, true);
		ship(3, 15, true);
		ship(4, 5, true);
		ship(4, 6, true);
		ship(5, 6, true);
		ship(6, 7, true);
		ship(7, 8, true);
		ship(8, 9, true);
		ship(9, 10, true);
		ship(9, 12, true);
		ship(10, 11, true);
		ship(11, 12, true);
		ship(12, 13, true);
		ship(13, 14, true);
		ship(13, 15, true);
		ship(16, 17, true);
		ship(16, 18, true);
		ship(17, 18, true);

		while (true) {
			int x, y;
			char command = in.nextLine().charAt(0);
			
			switch (command) {
			case 'i':
				x = in.nextInt();
				y = in.nextInt();
				
				ship(x, y, true);
				break;
			case 'd':
				x = in.nextInt();
				y = in.nextInt();
				
				ship(x, y, false);
				break;
			case 'n':
				x = in.nextInt();
				
				friends(x);
				break;
			case 'f':
				x = in.nextInt();
				
				FofF(x);				
				break;
			case 's':
				x = in.nextInt();
				y = in.nextInt();
				
				int deg = degOfSep(x, y);
				System.out.println(deg != 0 ? deg : "Not connected");
				break;
			default:
				return;
			}
			in.nextLine();
		}
	}

	private static void ship(int x, int y, boolean bool) {
		ships[x][y] = bool;
		ships[y][x] = bool;
	}
	
	private static void friends(int x) {
		int count = 0;
		for (int i = 1; i < 50; i++) {
			if (ships[x][i]) {
				count++;
			}
		}
		System.out.println(count);
	}
	
	private static void FofF(int x) {
		boolean[] visited = new boolean[50];
		visited[x] = true;

		for (int i = 1; i < 50; i++) {
			if (ships[x][i]) {
				visited[i] = true;
			}
		}
		
		int count = 0;
		for (int i = 1; i < 50; i++) {
			if (ships[x][i]) {
				for (int j = 1; j < 50; j++) {
					if (ships[i][j] && !visited[j]) {
						count++;
						visited[j] = true;
					}
				}
			}
		}
		System.out.println(count);
	}

	private static int degOfSep(int x, int y) {
		Queue<Integer> friends = new LinkedList<Integer>();
		int[] visited = new int[50];
		
		for (int i = 1; i < 50; i++) {
			if (ships[x][i]) {
				friends.add(i);
				visited[i] = 1;
			}
		}
		
		while (!friends.isEmpty()) {
			int temp = friends.poll();
			if (temp == y) {
				return visited[temp];
			}
			
			for (int i = 1; i < 50; i++) {
				if (ships[temp][i] && visited[i] == 0) {
					visited[i] = visited[temp] + 1;
					friends.add(i);
				}
			}
		}
		return 0;
	}
		
}
