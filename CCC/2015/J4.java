package ccc_2015;
import java.util.Scanner;

public class J4 {

	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		int M = in.nextInt();
		
		int[] history = new int[100];
		int time = 0;
		
		for (int i = 0; i < M; i++){
			char entry = in.next().charAt(0);
			int friend = in.nextInt();
			
			if (entry == 'W') {
				time += friend - 1;
			} else if (entry == 'R') {
				time++;
				history[friend - 1] -= time;
			} else {
				time++;
				history[friend - 1] += time;
			}
		}
		
		for (int i = 0; i < history.length; i++) {
			if (history[i] > 0) {
				System.out.println((i + 1) + " " + history[i]);
			} else if (history[i] < 0) {
				System.out.println((i + 1) + " " + "-1");
			}
		}
	}

}
