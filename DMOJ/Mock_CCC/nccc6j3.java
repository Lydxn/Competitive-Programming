import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		outer: for (int i = 0; i < T; i++) {
			int A = in.nextInt();
			int B = in.nextInt();
			int N = in.nextInt();

			for (int j = 0; ; j++) {
				for (int k = 0; ; k++) {
					int spend = A * j + B * k;
					if (spend == N) {
						System.out.println("YES");
						continue outer;
					} else if (spend > N) {
						break;
					}
				}

				if (j > N) {
					break;
				}
			}
			System.out.println("NO");
		}
    }
}
