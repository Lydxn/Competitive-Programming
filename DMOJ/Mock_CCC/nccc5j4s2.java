import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] gifts = new int[N];
		for (int i = 0; i < N; i++) {
			gifts[i] = in.nextInt();
		}

		int swap = 0;
		for (int j = 0; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (gifts[j] < gifts[k]) {
					swap++;
				}
			}
		}
		System.out.println(swap);
    }
}
