package ccc_2017;
import java.util.Arrays;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[] tides = new int[N];
		for (int i = 0; i < N; i++) {
			tides[i] = in.nextInt();
		}
		Arrays.sort(tides);

		if (N % 2 == 0) {
			for (int j = 0; j < N / 2; j++) {
				System.out.print(tides[N / 2 - j - 1] + " " + tides[N / 2 + j] + " ");
			}
		} else {
			for (int k = 1; k <= N / 2; k++) {
				System.out.print(tides[N / 2 - k + 1] + " " + tides[N / 2 + k] + " ");
			}
			System.out.println(tides[0]);
		}
	}
}
