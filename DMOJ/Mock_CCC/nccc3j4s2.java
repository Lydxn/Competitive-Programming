import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] medianOfMedians = new int[N];
		for (int i = 0; i < N; i++) {
			int[] median = new int[N];
			for (int j = 0; j < N; j++) {
				median[j] = in.nextInt();
			}
			Arrays.sort(median);
			medianOfMedians[i] = median[N / 2];
		}
		Arrays.sort(medianOfMedians);
		System.out.println(medianOfMedians[N / 2]);
    }
}
