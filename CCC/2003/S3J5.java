package ccc_2003;
import java.util.*;

public class S3_J5 {
	
	static char[][] house;
	static int r, c;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int flooring = in.nextInt();
		r = in.nextInt();
		c = in.nextInt();
		in.nextLine();
		
		house = new char[r][];
		for (int i = 0; i < r; i++) {
			house[i] = in.nextLine().toCharArray();
		}
		List<Integer> roomSizes = new ArrayList<Integer>();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (house[i][j] == '.') {
					roomSizes.add(area(i, j, 0));
				}
			}
		}
		
		Collections.sort(roomSizes);
		
		int rooms = 0;
		for (int i = roomSizes.size() - 1; i >= 0; i--) {
			int newFlooring = flooring - roomSizes.get(i);
			if (newFlooring >= 0) {
				flooring = newFlooring;
				rooms++;
			} else {
				break;
			}
		}
		System.out.println(rooms + " room" + (rooms == 1 ? "" : "s") + ", " + flooring + " square metre(s) left over");
	}
	
	private static int area(int x, int y, int area) {
		if (x >= 0 && x < r && y >= 0 && y < c && house[x][y] == '.') {
			house[x][y] = 'X';
			area++;
			
			area = area(x + 1, y, area);
			area = area(x, y + 1, area);
			area = area(x - 1, y, area);
			area = area(x, y - 1, area);
		}
		return area;
	}

}
