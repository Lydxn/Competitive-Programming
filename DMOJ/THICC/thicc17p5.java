import java.util.*;
import java.io.*;

public class P5 {
   public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer NK = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(NK.nextToken());
		int K = Integer.parseInt(NK.nextToken());

		int[] arr = new int[N];
		StringTokenizer a = new StringTokenizer(br.readLine());
		for (int i = 0; i < arr.length; i++) {
			arr[i] = Integer.parseInt(a.nextToken());
		}

		int[] distinct = new int[1000001];
		long res = 0;

		int l = 0;
		int r = 0;
		int size = 0;

		while (l < N) {
			while (r < N && size < K) {
				if (++distinct[arr[r++]] == 1) {
					size++;
				}
			}

			if (size < K) {
				break;
			}

			res += N - r + 1;
			if (--distinct[arr[l++]] == 0) {
				size--;
			}
		}
		System.out.println(res);
	}
}
