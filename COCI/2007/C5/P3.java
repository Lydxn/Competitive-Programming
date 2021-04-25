package COCI;
import java.util.Scanner;

public class COCI_2007_C5_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int[][] tri = new int[3][2];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				tri[i][j] = in.nextInt();
			}
		}
		
		int N = in.nextInt();
		int[][] trees = new int[N][2];
		int count = 0;
		double land = triArea(tri[0], tri[1], tri[2]);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				trees[i][j] = in.nextInt();
			}
			
			if (triArea(tri[0], tri[1], trees[i]) + 
				triArea(tri[1], tri[2], trees[i]) + 
				triArea(tri[0], tri[2], trees[i]) == land) {
				count++;	
			}
		}
		
		System.out.println(Math.round(land * 10) / 10.0);
		System.out.println(count);
	}

	public static double triArea(int[] p1, int[] p2, int[] p3) {
		return Math.abs(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1])) / 2.0;
	}
		
}