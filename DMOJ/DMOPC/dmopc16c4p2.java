import java.util.Arrays;
import java.util.Scanner;

public class dmopc16c4p2 {

	static class Batch {
		int f, e, p;
		public Batch(int f, int e, int p) {
			this.f = f;
			this.e = e;
			this.p = p;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int B = in.nextInt();

		Batch[] batches = new Batch[B];
		for (int i = 0; i < batches.length; i++) {
			batches[i] = new Batch(in.nextInt(), in.nextInt(), in.nextInt());
		}

		int F = in.nextInt();
		int[] t = new int[F];
		for (int i = 0; i < t.length; i++) {
			t[i] = in.nextInt();
		}
		Arrays.sort(t);

		int points = 0;
		for (Batch b : batches) {
			if (upperBound(t, b.e) < lowerBound(t, b.f)) {
				points += b.p;
			}
		}
		System.out.println(points);
	}

	private static int lowerBound(int[] arr, int val) {
		int lo = 0, hi = arr.length - 1, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (arr[mid] < val) lo = mid + 1;
			else 				hi = mid - 1;
		}
		return lo;
	}

	private static int upperBound(int[] arr, int val) {
		int lo = 0, hi = arr.length - 1, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (arr[mid] > val) hi = mid - 1;
			else 				lo = mid + 1;
		}
		return hi;
	}

}
