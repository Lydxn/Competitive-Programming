import java.util.Arrays;
import java.util.Scanner;

public class dmopc19c2p1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] data = new int[N];
		int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
		double Q1 = 0, Q2 = 0, Q3 = 0;

		for (int i = 0; i < data.length; i++) {
			data[i] = in.nextInt();
			min = Math.min(min, data[i]);
			max = Math.max(max, data[i]);
		}

		Arrays.sort(data);
		Q1 = median(data.clone(), 0, N / 2);
		Q2 = median(data.clone(), 0, N);
		Q3 = median(data.clone(), N - N / 2, N);

		System.out.println(min + " " + max + " " + Q1 + " " + Q2 + " " + Q3);
	}

	private static double median(int[] data, int l, int r) {
		Arrays.sort(data, l, r);
		int mid = (l + r) / 2;
		return (r - l) % 2 == 0 ? (data[mid - 1] + data[mid]) / 2.0 : data[mid];
	}

}
