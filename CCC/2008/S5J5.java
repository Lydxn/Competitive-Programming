package ccc_2008;
import java.util.Scanner;

public class S5_J5 {
	
	static int[][] reactions = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
	static byte[][][][] cache;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			int[] particles = new int[4];
			for (int j = 0; j < particles.length; j++) {
				particles[j] = in.nextInt();
			}
			
			cache = new byte[particles[0] + 1][particles[1] + 1][particles[2] + 1][particles[3] + 1];
			System.out.println(nukitWin(particles) == 1 ? "Patrick" : "Roland");
		}
	}
	
	private static int nukitWin(int[] particles) {
		if (cache[particles[0]][particles[1]][particles[2]][particles[3]] != 0) {
			return cache[particles[0]][particles[1]][particles[2]][particles[3]];
		}
		
		for (int i = 0; i < reactions.length; i++) {
			int[] temp = particles.clone();
			if (isLost(temp, i)) {
				continue;
			}
			
			for (int j = 0; j < temp.length; j++) {
				temp[j] -= reactions[i][j];
			}
			
			if (nukitWin(temp) == 0) {
				return cache[particles[0]][particles[1]][particles[2]][particles[3]] = 1;
			}
		}
		return cache[particles[0]][particles[1]][particles[2]][particles[3]] = 0;
	}
	
	private static boolean isLost(int[] temp, int reaction) {
		for (int i = 0; i < temp.length; i++) {
			if (temp[i] < reactions[reaction][i]) {
				return true;
			}
		}
		return false;
	}
	
}
