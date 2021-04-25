import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		long N = in.nextLong();

		long threshold = N * (N - 1) / 2;
		long result = 0;

 		for (long i = N - 1, count = 0; i >= 1; i--) {
			result += i;

			if (2 * result >= threshold) {
				System.out.println(count + 1);
				return;
			}
			count++;
		}
    }
}
