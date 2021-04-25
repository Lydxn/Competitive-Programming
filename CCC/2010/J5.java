package ccc_2010;
import java.util.Arrays;
import java.util.Scanner;

public class J5 {
	
	static int board[][] = new int[8][8];
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sX = in.nextInt() - 1;
		int sY = in.nextInt() - 1;
		int eX = in.nextInt() - 1;
		int eY = in.nextInt() - 1;
		
		for (int i = 0; i < 8; i++) {
			Arrays.fill(board[i], Integer.MAX_VALUE);
		}
		knight(sX, sY, 0);
		System.out.println(board[eX][eY]);
	}
	
	private static void knight(int sX, int sY, int steps) {
        if (sX >= 0 && sX < 8 && sY >= 0 && sY < 8 && steps < board[sX][sY]) {
            board[sX][sY] = steps;
            knight(sX + 1, sY + 2, steps + 1);
            knight(sX + 1, sY - 2, steps + 1);
            knight(sX - 1, sY + 2, steps + 1);
            knight(sX - 1, sY - 2, steps + 1);
            knight(sX + 2, sY + 1, steps + 1);
            knight(sX + 2, sY - 1, steps + 1);
            knight(sX - 2, sY + 1, steps + 1);
            knight(sX - 2, sY - 1, steps + 1);
        }
    }

}
