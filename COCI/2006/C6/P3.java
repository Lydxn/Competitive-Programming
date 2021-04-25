package COCI;
import java.util.Scanner;

public class COCI_2006_C6_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		char[][] ttt = new char[N][];
		for (int i = 0; i < N; i++) {
			ttt[i] = in.nextLine().toCharArray();
		}
		
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				char player = ttt[j][k];
				if (player != '.') {
					if ((k < N - 2 && ttt[j][k + 1] == player && ttt[j][k + 2] == player) || 
						(j < N - 2 && ttt[j + 1][k] == player && ttt[j + 2][k] == player) ||
						(j < N - 2 && k < N - 2 && ttt[j + 1][k + 1] == player && ttt[j + 2][k + 2] == player) || 
						(j < N - 2 && k > 1 && ttt[j + 1][k - 1] == player && ttt[j + 2][k - 2] == player)) {
						System.out.println(player);
						return;
					}
				}
			}
		}
		System.out.println("ongoing");
	}

}