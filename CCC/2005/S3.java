package ccc_2005;
import java.util.Scanner;

public class S3 {

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[][][] matrices = new int[N][][];
		for (int i = 0; i < matrices.length; i++) {
			int r = in.nextInt();
			int c = in.nextInt();
			matrices[i] = new int[r][c];
			
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					matrices[i][j][k] = in.nextInt();
				}
			}
		}
		
		int[][] tensor = matrices[0];
		for (int i = 1; i < matrices.length; i++) {
			tensor = tensorProd(tensor, matrices[i]);
		}
		
		int maxE = Integer.MIN_VALUE;
		int minE = Integer.MAX_VALUE;
		int maxR = Integer.MIN_VALUE;
		int minR = Integer.MAX_VALUE;
		int maxC = Integer.MIN_VALUE;
		int minC = Integer.MAX_VALUE;
		
		for (int[] x : tensor) {
			for (int y : x) {
				maxE = Math.max(maxE, y);
				minE = Math.min(minE, y);
			}
		}
		
		for (int x = 0; x < tensor.length; x++) {
			int sum = 0;
			for (int y = 0; y < tensor[0].length; y++) {
				sum += tensor[x][y];
			}
			maxR = Math.max(maxR, sum);
			minR = Math.min(minR, sum);
		}
		
		for (int x = 0; x < tensor[0].length; x++) {
			int sum = 0;
			for (int y = 0; y < tensor.length; y++) {
				sum += tensor[y][x];
			}
			maxC = Math.max(maxC, sum);
			minC = Math.min(minC, sum);
		}
		
		System.out.println(maxE + "\n" + minE + "\n" + maxR + "\n" + minR + "\n" + maxC + "\n" + minC);
	}
	
	private static int[][] tensorProd(int[][] A, int[][] B) {
		int[][] tensor = new int[A.length * B.length][A[0].length * B[0].length];
		for (int w = 0; w < A.length; w++) {
			for (int x = 0; x < A[0].length; x++) {
				for (int y = 0; y < B.length; y++) {
					for (int z = 0; z < B[0].length; z++) {
						tensor[w * B.length + y][x * B[0].length + z] = A[w][x] * B[y][z];
					}
				}
			}
		}
		return tensor;
	}

}
