import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] x = new int[N];
		int[] y = new int[N];
		for (int i = 0; i < N; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}

		Arrays.sort(x);
		Arrays.sort(y);

		int minX = x[(int) Math.ceil((double) N / 2 - 1)];
		int minY = y[(int) Math.ceil((double) N / 2 - 1)];

		long secs = 0;
		for (int i = 0; i < N; i++) {
			secs += Math.abs(minY - y[i]) + Math.abs(minX - x[i]);
		}
		System.out.println(secs);
	}
}
