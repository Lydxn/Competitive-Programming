import java.io.*;
import java.util.*;

public class P2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int N = in.nextInt();

			int factors = 0;
			for (int j = 2; j <= N; j++) {
				while (N % j == 0) {
					factors++;
					N /= j;
				}
			}
			System.out.println(factors == 1 ? 0 : factors);
		}
    }
}
