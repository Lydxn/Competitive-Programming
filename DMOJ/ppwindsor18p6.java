package DMOJ;
import java.util.*;

public class InterNAV {
	
	static List<Character> rooms = new ArrayList<Character>(Arrays.asList('1'));
	static int m, n;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		m = in.nextInt();
		n = in.nextInt();
		in.nextLine();
		
		char[][] grid = new char[n][m];
		for (int i = 0; i < grid.length; i++) {
			grid[i] = in.nextLine().toCharArray();
		}

		outer: for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1') {
					searchRooms(grid, i, j);
					break outer;
				}
			}
		}
		
		Collections.sort(rooms);
		for (char r : rooms) {
			System.out.print(r + " ");
		}
	}
	
	private static void searchRooms(char[][] grid, int r, int c) {
		if (r >= 0 && r < n && c >= 0 && c < m) {
			if (grid[r][c] == 'O' || grid[r][c] == '1') {
				grid[r][c] = '#';
				searchRooms(grid, r + 1, c);
				searchRooms(grid, r, c + 1);
				searchRooms(grid, r - 1, c);
				searchRooms(grid, r, c - 1);
			} else if (Character.isDigit(grid[r][c])) {
				rooms.add(grid[r][c]);
				grid[r][c] = '#';
			}
		}
	}

}