package ccc_2004;
import java.util.Arrays;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		int[] score = new int[n];
		int[] rank = new int[n];
		int[] worst = new int[n];

		Arrays.fill(worst, 1);
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				score[j] += in.nextInt();
			}

			for (int j = 0; j < n; j++) {
				int currRank = 1;
				for (int m = 0; m < n; m++) {
					if (m != j && score[m] > score[j]) {
						currRank++;
					}
				}
				
				worst[j] = Math.max(worst[j], currRank);
				rank[j] = currRank;
			}
		}
		
		for (int r = 0; r < rank.length; r++) {
			if (rank[r] == 1) {
				System.out.println("Yodeller " + (r + 1) + " is the TopYodeller: score " + score[r] + ", worst rank " + worst[r]);
			}
		}
	}

}
