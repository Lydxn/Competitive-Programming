import java.util.Scanner;

public class DMOPC_2014_C7_P5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long N = in.nextLong();
		System.out.println(powMod(2, N * (N + 1) >> 1, 998244353));
	}

	private static long powMod(long A, long B, int M) {
		long res = 1;
		while (B > 0) {
			if ((B & 1) == 1) res = res * A % M;
			B >>= 1;
			A = A * A % M;
		}
		return res;
	}

}
