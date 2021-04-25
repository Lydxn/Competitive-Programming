package ECOO;
import java.util.Scanner;

public class ECOO_2018_R2_P1 {

	static int[] leaf = new int[4];
	static int[] fish = new int[4];
	static int max = 0;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			max = 0;
			
			int C = in.nextInt();
			int O = in.nextInt();
			int W = in.nextInt();
			int S = in.nextInt();

			for (int j = 0; j < leaf.length; j++) {
				leaf[j] = in.nextInt();
			}

			for (int j = 0; j < fish.length; j++) {
				fish[j] = in.nextInt();
			}
			
			maxO(C, O, W, S);
			System.out.println(max);
		}
		
	}
	
	private static void maxO(int C, int O, int W, int S) {
		max = Math.max(max, O);
		if (C >= leaf[0] && W >= leaf[1]) {
			maxO(C - leaf[0], O + leaf[3], W - leaf[1], S + leaf[2]);
		}
		if (S >= fish[0] && O >= fish[1]) {
			maxO(C + fish[2], O - fish[1], W + fish[3], S - fish[0]);
		}
	}

}