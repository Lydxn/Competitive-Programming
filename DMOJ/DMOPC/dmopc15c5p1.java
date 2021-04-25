import java.util.Scanner;

public class DMOPC_2015_C5_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long A = in.nextInt();
		long B = in.nextInt();
		long X = in.nextLong() - 1;

		System.out.println(X / lcm(A, B) + 1);
	}

	private static long lcm(long A, long B) {
		return A * B / gcd(A, B);
	}

	private static long gcd(long A, long B) {
		return B == 0 ? A : gcd(B, A % B);
	}

}
