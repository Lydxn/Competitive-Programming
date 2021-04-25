import java.util.Scanner;

public class DMOPC_2014_C8_P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		long res = binarySearch(N);
		System.out.println(N == 1 ? 1 : res * (res * res + 1) / 2);
	}

	private static long binarySearch(int N) {
		long lo = 1, hi = 100000, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (mid * (mid + 1) / 2 > N) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		return lo;
	}

}
