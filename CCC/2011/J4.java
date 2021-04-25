package ccc_2011;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class J4 {
	
	static boolean[][] borehole = new boolean[401][200];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		fillHole(Arrays.asList(200, 200, 203, 205, 199, 203, 204, 205, 199, 207, 207, 207, 207, 207, 199, 200, 201, 202, 203, 204, 205, 206, 207, 200, 201, 202, 203, 205, 206), 
				 Arrays.asList(0, 1, 3, 3, 4, 4, 4, 4, 5, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 2, 2, 2, 2));
		
		char dir;
		int xPos = 199;
		int yPos = 4;
		boolean intersect = false;
		
		outer: do {
			dir = in.next().charAt(0);
			int dist = in.nextInt();
			
			int dx = 0;
			int dy = 0;
			
			switch (dir) {
			case 'l':
				dx = -1;
				break;
			case 'r':
				dx = 1;
				break;
			case 'u':
				dy = -1;
				break;
			case 'd':
				dy = 1;
				break;
			default:
				break outer;
			}

			while (dist > 0) {
				xPos += dx;
				yPos += dy;
				
				if (borehole[xPos][yPos]) {
					intersect = true;
				} else {
					borehole[xPos][yPos] = true;
				}
				dist--;
			}
			
			System.out.println((xPos - 200) + " " + (-yPos - 1) + (intersect ? " DANGER" : " safe"));
		} while (dir != 'q' && !intersect);
	}
	
	private static void fillHole(List<Integer> x, List<Integer> y) {
		for (int i = 0; i < x.size(); i++) {
			borehole[x.get(i)][y.get(i)] = true;
		}
	}

}
