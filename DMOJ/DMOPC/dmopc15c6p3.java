import java.util.Scanner;

public class DMOPC_2015_C6_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		long K = in.nextLong();

		long[] diff = new long[200002];
		for (int i = 0; i < M; i++) {
			int a = in.nextInt();
			int b = in.nextInt();

			diff[a]--;
			diff[b + 1]++;
		}

		diff[0] = M;
		for (int i = 1; i <= N; i++) diff[i] += diff[i - 1];
		diff[0] = 0;
		for (int i = 1; i <= N; i++) diff[i] += diff[i - 1];

		int min = Integer.MAX_VALUE;
		for (int l = 0, r = 1; r <= N; r++) {
			while (l <= r && diff[r] - diff[l] >= K) {
				min = Math.min(min, r - l++);
			}
		}
		System.out.println(min == Integer.MAX_VALUE ? -1 : min);
	}

}
