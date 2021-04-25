import java.util.Scanner;

public class DMOPC_2015_C6_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		double tilt = 0;
		for (int i = 0; i < N; i++) {
			tilt = (tilt + in.nextDouble()) % 360;
		}
		System.out.println(tilt);
	}

}
