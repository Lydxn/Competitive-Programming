package ccc_2018;
import java.util.Scanner;

public class S2_J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[][] table = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				table[i][j] = in.nextInt();
			}
		}

		int[][] result = rotate(table, N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(result[i][j] + " "); 
            }
            System.out.println();
        }
	}
	
	private static int[][] rotate(int[][] new_table, int size) { 
		while (!incremental(new_table, size)) { 
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size / 2; k++) {
					int temp = new_table[j][size - k - 1];
					new_table[j][size - k - 1] = new_table[j][k];
					new_table[j][k] = temp;
				}
			}
		
			for (int j = 0; j < size; j++) {
		        for (int k = j + 1; k < size; k++) {
		        	int temp = new_table[j][k];
		        	new_table[j][k] = new_table[k][j];
		        	new_table[k][j] = temp;
		        }
		    }
		}
		return new_table;
	}
	
	private static boolean incremental(int[][] table, int size) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (table[i][j] > table[i + 1][j] || table[i][j] > table[i][j + 1]) {
					return false;
				}
			}
		}
		return true;
	}

}
