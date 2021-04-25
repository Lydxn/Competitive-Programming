import java.io.*;
import java.util.*;

public class P3 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] dolls = new int[101];
		for (int i = 0; i < N; i++) {
			dolls[in.nextInt()]++;
		}

		int min = -1;
		int max = -1;

		for (int i = 0; i < dolls.length; i++) {
			if (dolls[i] != 0) {
				if (min == -1 || dolls[i] < dolls[min]) {
					min = i;
				}

				if (max == -1 || dolls[i] >= dolls[max]) {
					max = i;
				}
			}
		}
		System.out.println(Math.abs(min - max));
	}
}
