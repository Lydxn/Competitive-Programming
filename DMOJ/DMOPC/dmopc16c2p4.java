import java.util.Scanner;

public class dmopc16c2p4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		System.out.println(binarySearch(b + 1) - binarySearch(a));
	}

	private static long binarySearch(int x) {
		long lo = 1, hi = 5000000000L, mid;
		while (lo < hi) {
			mid = (lo + hi) / 2;
			if (zeros(mid) >= x) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		return lo;
	}

	private static long zeros(long x) {
		int count = 0;
		for (long i = 5; i <= x; i *= 5) {
			count += x / i;
		}
		return count;
	}

}
