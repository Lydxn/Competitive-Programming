import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int N = in.nextInt();

			for (int j = 0, dots = N / 2, hashes = 1; j < N; j++) {
				System.out.print(String.join("", Collections.nCopies(dots, ".")));
				System.out.print(String.join("", Collections.nCopies(hashes, "#")));
				System.out.println(String.join("", Collections.nCopies(dots, ".")));

				dots = j < N / 2 ? dots - 1 : dots + 1;
				hashes = j < N / 2 ? hashes + 2 : hashes - 2;
			}
		}
    }
}
