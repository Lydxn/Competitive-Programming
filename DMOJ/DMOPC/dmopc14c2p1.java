import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int D = in.nextInt();

		for (int i = 1; i <= D; i++) {
			int T = in.nextInt();
			int sum = 0;

			for (int j = 0; j < T; j++) {
				sum += in.nextInt();
			}
			System.out.println(sum == 0 ? "Weekend" : "Day " + i + ": " + sum);
		}
	}
}
