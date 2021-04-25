import java.util.Scanner;

public class DMOPC_2015_C5_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int E = in.nextInt();
		int N = in.nextInt();
		in.nextLine();

		String[] bases = new String[N + 1];
		for (int i = 0; i < N; i++) {
			bases[N - i - 1] = Integer.toString(in.nextInt());
		}
		bases[N] = Integer.toString(E);

		int D = 10;
		for (String b : bases) {
			D = D == 1 ? b.length() : Integer.parseInt(b, D);
		}
		System.out.println(D);
	}

}
