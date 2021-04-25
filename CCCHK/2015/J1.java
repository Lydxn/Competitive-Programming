import java.io.*;
import java.util.*;

public class J1 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();

		String[] alice = in.nextLine().split(" ");
		String[] bob = in.nextLine().split(" ");

		int aCount = 0;
		int bCount = 0;

		for (int i = 0; i < N; i++) {
			int winner = winner(alice[i], bob[i]);
			if (winner == 0) {
				aCount++;
			} else if (winner == 1) {
				bCount++;
			}
		}
		System.out.println(aCount + " " + bCount);
	}

	private static int winner(String a, String b) {
		int aCode = a.equals("rock") ? 0 : (a.equals("paper") ? 1 : 2);
		int bCode = b.equals("rock") ? 0 : (b.equals("paper") ? 1 : 2);

		if ((bCode + 1) % 3 == aCode) {
			return 0;
		} else if ((aCode + 1) % 3 == bCode) {
			return 1;
		} else {
			return 2;
		}
	}
}
