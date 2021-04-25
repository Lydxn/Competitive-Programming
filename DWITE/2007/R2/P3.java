import java.io.*;
import java.util.*;

public class P3 {

    static int R, C;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		R = in.nextInt();
		C = in.nextInt();
		in.nextLine();

		char[][] house = new char[R][C];
		for (int i = 0; i < house.length; i++) {
			house[i] = in.nextLine().toCharArray();
		}

		int[] area = new int[5];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (Character.isDigit(house[i][j])) {
					area[house[i][j] - '1'] = findArea(house, i, j);
				}
			}
		}

		for (int a : area) {
			System.out.println(a);
		}
	}

	private static int findArea(char[][] house, int i, int j) {
		int count = 0;
		if (i >= 0 && i < R && j >= 0 && j < C && house[i][j] != '#') {
			house[i][j] = '#';
			count++;
			count += findArea(house, i + 1, j);
			count += findArea(house, i - 1, j);
			count += findArea(house, i, j + 1);
			count += findArea(house, i, j - 1);
		}
		return count;
	}

}
