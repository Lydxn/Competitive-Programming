import java.util.Scanner;

public class DMOPC_2015_C6_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int Ei = in.nextInt();
		int Ef = in.nextInt();
		int Eb = in.nextInt();
		int B = in.nextInt();
		int C = in.nextInt();

		long fish = 0;
		for (; Ei < Ef; fish++) {
			if (Eb >= B) {
				Eb -= B;
				Ei += 3 * B;
			} else {
				Eb = 0;
				Ei += Eb + 2 * B;
			}
		}
		System.out.println(fish + "\n" + fish * C);
	}

}
