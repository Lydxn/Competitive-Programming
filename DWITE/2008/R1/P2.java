import java.io.*;
import java.util.*;

public class P2 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		for (int i = 0; i < 5; i++) {
			int n = in.nextInt();
			char ch = in.next().charAt(0);
			System.out.println("ABCDEFGHI".charAt(sum(n) - 1) == ch ? "match" : "error");
		}
	}

	public static int sumDigits(int i) {
	    return i == 0 ? 0 : i % 10 + sumDigits(i / 10);
	}

	public static int sum(int n) {
		return n < 10 ? n : sum(sumDigits(n));
	}
}
