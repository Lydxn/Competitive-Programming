import java.util.Scanner;

public class P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int M = in.nextInt();

			int sum = (M + 1) * (M + 2) / 2;
			for (int j = 0; j < M; j++) {
				sum -= in.nextInt();
			}
			System.out.println(sum);
		}
	}

}
