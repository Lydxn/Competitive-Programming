import java.util.Scanner;

public class DMOPC_2015_C2_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long N = in.nextLong();
		long K = in.nextLong();

		long cuts = 0, pieces = 1;
		for (long min = Math.min(N, K); pieces < min; pieces <<= 1, cuts++);
		System.out.println(cuts + (N - pieces + K - 1) / K);
	}

}
