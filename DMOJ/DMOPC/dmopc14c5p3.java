import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] S = new int[N];
		for (int i = 0; i < S.length; i++) {
			S[i] = in.nextInt();
		}

		int maxSeq = 0;
		for (int i = 0; i < S.length; i++) {
			int j = i + 1;
			for (; j < S.length && Math.abs(S[j] - S[j - 1]) <= 2; j++);
			maxSeq = Math.max(maxSeq, j - i);
		}
		System.out.println(maxSeq);
	}
}
