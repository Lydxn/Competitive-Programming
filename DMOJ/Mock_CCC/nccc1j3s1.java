import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int K = in.nextInt();
		int P = in.nextInt();
		int X = in.nextInt();

		int M = 1;
		double current = 1;
		double next = 0;

		while (next < current) {
			current = (1.0 * M * X) + (1.0 * K * P / M);
			next = (1.0 * (M + 1) * X) + (1.0 * K * P / (M + 1));
			if (next > current) {
				break;
			}
			M++;
		}
		System.out.printf("%.3f", current);
		System.out.println();
    }
}
