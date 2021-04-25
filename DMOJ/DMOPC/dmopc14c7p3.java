import java.util.Scanner;

public class DMOPC_2014_C8_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int A = in.nextInt();
		int B = in.nextInt();

		boolean[] bivalves = new boolean[1000000];
		int count = 0;

		int[] right = new int[A];
		for (int i = 0; i < right.length; i++) {
			bivalves[in.nextInt()] = true;
		}

		int[] left = new int[B];
		for (int i = 0; i < left.length; i++) {
			if (bivalves[in.nextInt()]) {
				count++;
			}
		}
		System.out.println(N - count);
	}

}
