package DMOJ;
import java.util.Arrays;
import java.util.Scanner;

public class World_Trade_Foundation {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		
		int[] coins = new int[N];
		for (int i = 0; i < coins.length; i++) {
			coins[i] = in.nextInt();
		}
		Arrays.sort(coins);
		
		int minCoins = 0;
		for (int i = coins.length - 1; i >= 0 && K > 0; i--) {
			int take = K / coins[i]; 
			minCoins += take;
			K -= take * coins[i];
		}
		System.out.println(K == 0 ? minCoins : -1);
	}

}
