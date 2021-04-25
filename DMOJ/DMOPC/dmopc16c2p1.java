import java.util.Scanner;

public class dmopc16c2p1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();

		int[] powers = new int[4];
		for (int i = 0; i < K; i++) {
			powers[in.nextInt()]++;
		}
		System.out.println(0.5 * powers[1] + powers[2] + 5 * powers[3] < N ? "Continue" : "Return");
	}

}
