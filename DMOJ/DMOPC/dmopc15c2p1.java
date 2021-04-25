import java.util.Scanner;

public class DMOPC_2015_C2_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();

		int swords = 0;
		while (N >= K) {
			swords += K;
			N -= K - 1;
		}
		System.out.println(swords + N);
	}

}
