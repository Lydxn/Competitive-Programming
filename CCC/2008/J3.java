package ccc_2008;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String word = in.nextLine();
		
		int row = 0;
		int col = 0;
		int movements = 0;
		
		for (int i = 0, lastRow = 0, lastCol = 0; i < word.length(); i++) {
			if (word.charAt(i) == ' ') {
				row = 2;
				col = 4;
			} else if (word.charAt(i) == '-') {
				row = 3;
				col = 4;
			} else if (word.charAt(i) == '.') {
				row = 4;
				col = 4;
			} else {
				row = (word.charAt(i) - 65) % 6;
				col = (word.charAt(i) - 65) / 6;
			}
			movements += Math.abs(row - lastRow) + Math.abs(col - lastCol);
			lastRow = row;
			lastCol = col;
		}
		
		movements += Math.abs(row - 5) + Math.abs(col - 4);
		System.out.println(movements);
	}

}
