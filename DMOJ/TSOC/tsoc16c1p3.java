package DMOJ;
import java.util.Scanner;

public class You_And_Crossroads {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		int[] quadrants = new int[4];
		for (int i = 0; i < 2 * N; i++) {
			char[] line = in.nextLine().toCharArray();
			for (int j = 0; j < 2 * N; j++) {
				quadrants[i < N ? (j < N ? 1 : 0) : (j < N ? 2 : 3)] += line[j] == 'g' ? 1 : 0;
			}
		}
		
		int max = 0;
		int maxQuadrant = 0;
		for (int i = 0; i < quadrants.length; i++) {
			if (max < quadrants[i]) {
				max = quadrants[i];
				maxQuadrant = i;
			}
		}
		System.out.println(maxQuadrant + 1);
	}

}
