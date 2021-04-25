package DMOJ;
import java.util.Scanner;

public class Tic_Tac_Moe {
	
	static char[] ttt = new char[9];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		for (int i = 0; i < 9; i += 3) {
			String line = in.nextLine();
			for (int j = i; j < i + 3; j++) {
				ttt[j] = line.charAt(j - i);
			}
		}

		boolean[] players = {false, false};
		int[][] wins = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
		
		for (int[] w : wins) {
			int res = check(w);
			if (res != -1) {
				players[res] = true;
			}
		}
		
		System.out.println(players[0] && players[1] ? "Error, redo" : 
						 (!players[0] && !players[1] ? "Tie" : 
						  (players[0] && !players[1] ? "Timothy" : 
								  					   "Griffy")));
	}
	
	private static int check(int[] win) {
		return ttt[win[0]] == ttt[win[1]] && ttt[win[1]] == ttt[win[2]] ? (ttt[win[0]] == 'X' ? 0 : 1) : -1;
	}

}