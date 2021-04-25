import java.io.*;
import java.util.*;

public class P4 {
    static Integer[] coins;
	static int[] cache;
	static int m;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			m = in.nextInt();
			int n = in.nextInt();

			coins = new Integer[n];
			cache = new int[101];

			for (int j = 0; j < coins.length; j++) {
				coins[j] = in.nextInt();
			}
			Arrays.sort(coins, Collections.reverseOrder());

			int min = minCoins(0, 0);
			System.out.println(min);
		}
	}

	private static int minCoins(int change, int amount) {
		if (change == m) {
			return amount;
		} else if (cache[change] > 0) {
			return cache[change];
		} else {
			int best = Integer.MAX_VALUE;
			for (int i : coins) {
				if (change + i <= m) {
					best = Math.min(best, minCoins(change + i, amount + 1));
				}
			}
			return cache[change] = best;
		}
	}
}
