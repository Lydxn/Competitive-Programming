import java.util.Scanner;

public class DMOPC_2015_C3_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		long avg = 0;
		long[] slices = new long[N];

		for (int i = 0; i < slices.length; i++) {
			slices[i] = in.nextLong();
			avg += slices[i];
		}

		if (avg % N != 0) {
			System.out.println("Impossible");
			return;
		}
		avg /= N;

		long res = 0;
		for (long s : slices) {
			if (s > avg) {
				res += s - avg;
			}
		}
		System.out.println(res);
	}

}
