import java.util.Scanner;

public class dmopc16c3p2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		int D = in.nextInt();

		int[] jacks = new int[K];
		for (int i = 0, x = 0, y = 0; i < N; i++) {
			char oper = in.next().charAt(0);
			if (oper == 'T') {
				jacks[x++] = 1;
			} else {
				int q = in.nextInt();
				for (int j = y; j < x; j++) {
					jacks[j] *= q;
					if (jacks[j] > D) {
						jacks[j] = 0;
						y = j;
					}
				}
			}
		}

		for (int j : jacks) {
			System.out.println(j == 0 ? "dust" : j);
		}
	}

}
