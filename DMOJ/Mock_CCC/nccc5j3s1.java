import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int X = in.nextInt();

		int[] spikes = new int[N];
		for (int i = 0; i < N; i++) {
			spikes[i] = in.nextInt();
		}
		Arrays.sort(spikes);

		int median = 0;
		for (int j = 0; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (spikes[k] == X) {
					for (int l = k + 1; l < N; l++) {
						median++;
					}
				}
			}
		}
		System.out.println(median);
    }
}
