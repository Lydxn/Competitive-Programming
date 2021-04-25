import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
		long N = in.nextLong();

		long[] arr = new long[(int) N];
		for (int i = 0; i < N; i++) {
			arr[i] = in.nextInt();
		}
		Arrays.sort(arr);

		long sum = Arrays.stream(arr).sum();
		long max = Arrays.stream(arr).max().getAsLong();

		System.out.println(Math.min(sum - max, sum / 2));
    }
}
