import java.util.Scanner;

public class dmopc16c1p1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int count = 0;
		for (int i = 0; i < N; i++) {
			if (in.nextInt() % 2 == i % 2) {
				count++;
			}
		}
		System.out.println(count);
	}

}
