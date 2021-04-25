import java.io.*;
import java.util.*;

public class Main {
    static final double RADIANS = Math.PI / 180;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();

		double h = 0;
		for (int i = 0; i < n; i++) {
			int s = in.nextInt();
			int x = in.nextInt();
			double t = in.nextDouble();

			h += t * s * Math.sin(x * RADIANS);
		}
		System.out.println(Math.round(Math.sqrt(19.6 * h)));
	}
}
