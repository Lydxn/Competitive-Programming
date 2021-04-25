import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();

		int[] arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = in.nextInt();
		}
		Arrays.sort(arr);

		int res = 0;
		for (int i = 0; i < arr.length; i++) {
			res = Math.max(res, lower_bound(arr, i, arr[i] + K) - i);
		}
		System.out.println(res + 1);
	}

	private static int lower_bound(int[] arr, int l, int val) {
		int L = l, R = arr.length - 1, M, ans = -1;
		while (L <= R) {
			M = (L + R) / 2;
			if (val < arr[M]) {
				R = M - 1;
			} else {
				ans = M;
				L = M + 1;
			}
		}
		return ans;
	}
}
