import java.util.Scanner;

public class DMOPC_2014_C7_P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		int H = in.nextInt();

		int[] T = new int[N];
		for (int i = 0; i < N; i++) {
			T[i] = in.nextInt();
		}

		int breaks = 0;
		for (int i = N - 2; i >= 0; i--)
		{
			int diff = T[i + 1] - T[i] - H;
			if (diff > 0) {
				int B = (diff + M - 1) / M;
				breaks += B;
				T[i] += B * M;
			}
		}
		System.out.println(breaks);
	}

}
