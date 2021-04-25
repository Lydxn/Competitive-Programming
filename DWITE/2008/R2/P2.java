import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int N = in.nextInt();

			int max = 0;
			for (; N > 0; N /= 10) {
				max = Math.max(N % 10, max);
			}
			System.out.println(max);
		}
    }
}
