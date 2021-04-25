import java.util.Scanner;

public class dmopc19c2p0 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int Hmin = in.nextInt(), Hmax = in.nextInt();

		int count = 0;
		for (int i = 0; i < N; i++) {
			int h = in.nextInt();
			if (h >= Hmin && h <= Hmax) count++;
		}
		System.out.println(count);
	}

}
