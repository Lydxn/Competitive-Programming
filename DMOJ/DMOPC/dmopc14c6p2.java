import java.util.Scanner;

public class DMOPC_2014_C7_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt() - 1;

		int[] on = new int[N], off = new int[N];
		for (int i = 0; i < N; i++) {
			on[i] = in.nextInt();
			off[i] = in.nextInt();
		}

		int min = on[0], max = on[0];
		for (int i = 1, notFirst = 0; i < N; i++) {
			if (notFirst > off[i]) {
				notFirst -= off[i];
			} else {
				max -= off[i] - notFirst;
				notFirst = 0;
			}

			notFirst += on[i];
			min -= off[i];
		}
		System.out.println(Math.max(0, min) + "\n" + Math.max(0, max));
	}

}
