package DMOJ;
import java.io.*;

public class Miniature_Sudoku {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int Q = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < Q; i++) {
			int[][] sudoku = new int[4][4];
			for (int j = 0; j < sudoku.length; j++) {
				String line = br.readLine();
				
				for (int k = 0; k < sudoku.length; k++) {
					char ch = line.charAt(k);
					sudoku[j][k] = Character.isDigit(ch) ? ch - '0' : 0;
				}
			}
			solve(sudoku);
		}
	}
	
	private static boolean solve(int[][] sudoku) {
		for (int r = 0; r < sudoku.length; r++) {
			for (int c = 0; c < sudoku.length; c++) {
				if (sudoku[r][c] == 0) {
					for (int i = 1; i <= 4; i++) {
						sudoku[r][c] = i;
						if (isCandidate(sudoku, r, c) && solve(sudoku)) {
							return true;
						}
						sudoku[r][c] = 0;
					}
					return false;
				}
			}
		}
		
		for (int[] i : sudoku) {
			for (int j : i) {
				System.out.print(j);
			}
			System.out.println();
		}
		return true;
	}
	
	private static boolean isCandidate(int[][] sudoku, int r, int c) {
		boolean[] rowNums = new boolean[4];
		for (int i = 0; i < 4; i++) {
			int curr = sudoku[r][i];
			if (curr != 0) {
				if (!rowNums[curr - 1]) {
					rowNums[curr - 1] = true;
				} else {
					return false;
				}
			}
		}
		
		boolean[] colNums = new boolean[4];
		for (int i = 0; i < 4; i++) {
			int curr = sudoku[i][c];
			if (curr != 0) {
				if (!colNums[curr - 1]) {
					colNums[curr - 1] = true;
				} else {
					return false;
				}
			}
		}
		
		int rS = r / 2 * 2;
		int cS = c / 2 * 2;
		boolean[] secNum = new boolean[4];
		for (int i = rS; i < rS + 2; i++) {
			for (int j = cS; j < cS + 2; j++) {
				int curr = sudoku[i][j];
				if (curr != 0) {
					if (!secNum[curr - 1]) {
						secNum[curr - 1] = true;
					} else {
						return false;
					}
				}
			}
		}
		return true;
	}

}
