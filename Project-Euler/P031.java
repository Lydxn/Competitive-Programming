package euler100;

public class P031 {

	public static void main(String[] args) {
		int target = 200;
		int[] coins = {1, 2, 5, 10, 20, 50, 100, 200};
		int[] ways = new int[target + 1];
		ways[0] = 1;
		
		for (int i : coins) {
			for (int j = i; j <= target; j++) {
				ways[j] += ways[j - i];
			}
		}
		System.out.println(ways[target]);
	}

}
