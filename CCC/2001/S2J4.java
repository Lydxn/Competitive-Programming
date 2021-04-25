package ccc_2001;
import java.util.Scanner;

public class S2_J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Start value:");
		int start = in.nextInt();
		System.out.println("End value:");
		int end = in.nextInt();
		
		int[][] spiral = new int[10][10];
		int[][] dir = {{0, -1, 0, 1}, {1, 0, -1, 0}};
		int x = 4;
		int y = 4;
		int currDir = 2;
		
		for (int i = start; i <= end; i++) {
			spiral[y][x] = i;
			if (spiral[y + dir[0][(currDir + 1) % 4]]
					  [x + dir[1][(currDir + 1) % 4]] == 0) {
				currDir++;
			}
			y += dir[0][currDir % 4];
			x += dir[1][currDir % 4];
		}
		
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (spiral[j][k] == 0) {
					System.out.printf("%4s", "");
				} else {
					System.out.printf("%4d", spiral[j][k]);
				}
			}
			System.out.println();
		}
	}	

}
