package AtCoder.DP;
import java.util.Arrays;
import java.util.Scanner;

public class Deque {
	
	static int[] a;
	static long[][] cache;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		a = new int[N];
		cache = new long[N][N];
		
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		
		for (int i = 0; i < cache.length; i++) {
			Arrays.fill(cache[i], -1);
		}
		System.out.println(diff(0, a.length - 1));
	}
	
	private static long diff(int left, int right) {
		if (cache[left][right] != -1) { 
			return cache[left][right];
		} else if (left == right) {
			return cache[left][right] = a[left];
		} else {
			return cache[left][right] = Math.max(a[right] - diff(left, right - 1), 
												 a[left] - diff(left + 1, right));
		}
	}

}