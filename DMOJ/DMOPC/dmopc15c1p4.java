import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int X = in.nextInt();

		if (N == 1) {
			System.out.println(0);
			return;
		}

		List<Integer> ESieve = ESieve(N);
		long res = 0;

		for (int i : ESieve) {
			int rem = N - i;
			res += rem / X + 1 + (--rem >= 0 ? rem / X + 1 : 0);
		}
		System.out.println(res);
	}

	private static List<Integer> ESieve(int lim) {
		BitSet bits = new BitSet(lim + 1);
		bits.flip(2, lim + 1);

		List<Integer> primes = new ArrayList<Integer>();
		for (int i = 2; i * i < bits.length(); i++) {
			if (bits.get(i)) {
				for (int j = i * i; j < bits.length(); j += i) {
					bits.clear(j);
				}
			}
		}

		for (int i = 0; i < bits.length(); i++) {
			if (bits.get(i)) {
				primes.add(i);
			}
		}
		return primes;
	}

}
