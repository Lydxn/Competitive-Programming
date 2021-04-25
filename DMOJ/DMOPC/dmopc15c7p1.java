import java.util.Scanner;

public class DMOPC_2015_C7_P1 {

	static class Kemonomini {
		int idx, P, S, T;

		public Kemonomini(int idx, int P, int S, int T) {
			this.idx = idx;
			this.P = P;
			this.S = S;
			this.T = T;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] cuteness = new int[4];
		for (int i = 0; i < cuteness.length; i++) {
			cuteness[i] = in.nextInt();
		}

		int Smax = 0;
		Kemonomini[] problems = new Kemonomini[N];
		for (int i = 0; i < problems.length; i++) {
			problems[i] = new Kemonomini(in.nextInt() - 1, in.nextInt(), in.nextInt(), in.nextInt());
			Smax = Math.max(Smax, problems[i].S);
		}

		for (Kemonomini p : problems) {
			if (p.P == 10) {
				System.out.println(0);
			} else if (p.T * cuteness[p.idx] + Smax <= 180) {
				System.out.println(10 - p.P);
			} else {
				System.out.println("The kemonomimi are too cute!");
			}
		}
 	}

}
