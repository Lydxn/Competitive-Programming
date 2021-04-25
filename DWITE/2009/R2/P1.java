import java.util.Scanner;

public class P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			int x2 = in.nextInt();
			int y2 = in.nextInt();

			double angle = Math.atan2(y1, x1) - Math.atan2(y2, x2);
			if (angle < 0) angle += 2 * Math.PI;

			System.out.printf("%.1f\n", Math.toDegrees(angle));
		}
	}

}
