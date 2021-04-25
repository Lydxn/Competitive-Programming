package ccc_2016;
import java.util.Arrays;
import java.util.Scanner;

public class S2_J5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int question = in.nextInt();
		int N = in.nextInt();
		
		int[] dmoj = new int[N];
		int[] peg = new int[N];
		
		for (int d = 0; d < N; d++) {
			dmoj[d] = in.nextInt();
		}
		
		for (int p = 0; p < N; p++) {
			peg[p] = in.nextInt();
		}
		
		Arrays.sort(dmoj);
		Arrays.sort(peg);
		
		int total = 0;
		if (question == 1) {
			for (int i = 0; i < N; i++) {
				total += Math.max(dmoj[i], peg[i]);
			}
		} else {
			for (int j = 0; j < N; j++) {
				total += Math.max(dmoj[j], peg[N - j - 1]);
			}
		}
		System.out.println(total);
	}

}
