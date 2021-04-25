import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int L = in.nextInt();
		int R = in.nextInt();

		int[] B = new int[N];
		for (int i = 0; i < B.length; i++) {
			B[i] = in.nextInt();
		}
		Arrays.sort(B);

		int strength = 0;
		for (int i = B.length - R; i >= 0; i -= L) {
			strength += B[i];
		}
		System.out.println(strength);
	}
}
