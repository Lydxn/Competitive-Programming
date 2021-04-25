import java.util.*;
import java.io.*;

public class P1 {

    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int[] times = new int[N];
		for (int i = 0; i < times.length; i++) {
			int M = in.nextInt();
			int S = in.nextInt();
			times[i] = M * 60 + S;
		}
		Arrays.sort(times);

		int X = in.nextInt();
		int Y = in.nextInt();
		int lim = X * 60 + Y;

		int songs = 0;
		int sum = 0;

		for (int t : times) {
			sum += t;
			if (sum <= lim) {
				songs++;
			}
		}
		System.out.println(songs);
	}
}
