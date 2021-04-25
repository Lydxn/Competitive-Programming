import java.util.Arrays;
import java.util.Scanner;

public class DMOPC_2015_C7_P4 {

	static boolean[] sieve = new boolean[2000];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int K = in.nextInt(), D = in.nextInt();
		int Sa = in.nextInt(), Sb = in.nextInt();
		int Pa = in.nextInt(), Pb = in.nextInt();

		boolean[][] visited = new boolean[1000][1000];
		boolean winner = false;

		initSieve();
		while (!visited[Pa][Pb]) {
			visited[Pa][Pb] = true;
			if (Math.abs(Pa - Pb) < D || Math.abs(Pa - Pb + K) < D) {
				Pb = Pa < Pb ? (Pa + D) % K : (Pa - D + K) % K;
			}

			if (sieve[Math.min(Pa, K - Pa) + Math.min(Pb, K - Pb)]) {
				winner = true;
				break;
			}

			Pa = (Pa + Sa) % K;
			Pb = (Pb + Sb) % K;
		}
		System.out.println(winner ? "Alice" : "Bob");
	}

	private static void initSieve() {
		Arrays.fill(sieve, true);
		sieve[0] = false;
		sieve[1] = false;

		for (int i = 2; i < sieve.length; i++) {
			if (sieve[i]) {
				for (int j = i * i; j < sieve.length; j += i) {
					sieve[j] = false;
				}
			}
		}
	}

}
