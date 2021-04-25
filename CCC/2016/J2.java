package ccc_2016;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int[][] square = new int[4][4]; 
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				square[i][j] = in.nextInt(); 
			}
		}
		
		int total = square[0][0] + square[0][1] + square[0][2] + square[0][3];
		for (int i = 1; i < 4; i++) {
			if (square[i][0] + square[i][1] + square[i][2] + square[i][3] != total) {
				System.out.println("not magic");
				return;
			}
		}
		
		for (int i = 0; i < 4; i++) {
			if (square[0][i] + square[1][i] + square[2][i] + square[3][i] != total) {
				System.out.println("not magic");
				return;
			}
		}
		System.out.println("magic");
	}
	
}
