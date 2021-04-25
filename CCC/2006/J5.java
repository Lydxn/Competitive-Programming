package ccc_2006;
import java.util.Scanner;

public class J5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char config = in.next().charAt(0);
		int n = in.nextInt();
		
		int[][] moves = new int[n][2];
		for (int i = 0; i < n; i++) {
			moves[i][0] = in.nextInt();
			moves[i][1] = in.nextInt();
		}
		
		int[][] othello = new int[8][8];
		int[] xAdj = {-1, 0, 1, 1, 1, 0, -1, -1};
		int[] yAdj = {1, 1, 1, 0, -1, -1, -1, 0};
		
		// black = 1, white = 2
		if (config == 'a') {
			othello[3][3] = 2;
			othello[3][4] = 1;
			othello[4][3] = 1;
			othello[4][4] = 2;
		} else if (config == 'b') {
			for (int j = 0; j < 8; j++) {
				othello[j][j] = 1;
				othello[7 - j][j] = 2;
			}
		} else {
			for (int j = 0; j < 8; j++) {
				othello[j][2] = 1;
				othello[j][3] = 1;
				othello[j][4] = 2;
				othello[j][5] = 2;
			}
		}
		
		for (int k = 0; k < n; k++) {
			int colour = k % 2 + 1;
			int opColour = colour == 1 ? 2 : 1;
			int x = moves[k][1] - 1;
			int y = moves[k][0] - 1;
			
			othello[y][x] = colour;
			for (int l = 0; l < 8; l++) {
				int dist = 0;
				for (int m = 2; m < 7; m++) {
					int xCh = x + xAdj[l] * m;
					int yCh = y + yAdj[l] * m;
					if (xCh < 0 || xCh > 7 || yCh < 0 || yCh > 7) {
						break;
					} else if (othello[yCh][xCh] == colour) {
						dist = m;
					}
				}
				
				for (int o = 1; o < dist; o++) {
					if (othello[y + yAdj[l] * o][x + xAdj[l] * o] == opColour) {
						othello[y + yAdj[l] * o][x + xAdj[l] * o] = colour;
					}
				}
			}
		}
		
		int black = 0;
		int white = 0;
		for (int p = 0; p < 8; p++) {
			for (int q = 0; q < 8; q++) {
				if (othello[q][p] == 1) {
					black++;
				} else if (othello[q][p] == 2) {
					white++;
				}
			}
		}
		System.out.println(black + " " + white);
	}
	
}
