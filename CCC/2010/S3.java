import java.util.Arrays;
import java.util.Scanner;

public class S3 {
	
	static int[] houses;
	static int H;
	static final int CIRCUM = 1000000;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		H = in.nextInt();
		
		houses = new int[2 * H];
		for (int i = 0; i < H; i++) houses[i] = in.nextInt();
		Arrays.sort(houses, 0, H);
		for (int i = 0; i < H; i++) houses[i + H] = houses[i] + CIRCUM;
		
		
		int K = in.nextInt();
		System.out.println(binarySearch(K));
	}
	
	private static int binarySearch(int K) {
		int lo = 0, hi = CIRCUM, mid;
		while (lo < hi) {
			mid = (lo + hi) / 2;
			if (minHydrants(mid) > K) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		return lo;
	}
	
	private static int minHydrants(int mid) {
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < H; i++) {
			int hydrants = 1, currIdx = i;
			for (int j = i; j < i + H; j++) {
				if (houses[j] > houses[currIdx] + 2 * mid) {
					currIdx = j;
					hydrants++;
				}
			}
			min = Math.min(min, hydrants);
		}
		return min;
	}
}
