import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] cacti = new int[10];
		for (int i = 0; i < N; i++) {
			cacti[in.nextInt() - 1]++;
		}

		int count = -1;
		int ans = 0;
		for (int j = 0; j < 10; j++) {
			if (count < cacti[j]) {
				count = cacti[j];
				ans = j + 1;
			}
		}
		System.out.println(ans);
    }
}
