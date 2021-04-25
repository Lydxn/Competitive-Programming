import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int max = Integer.MIN_VALUE;
		for (int i = 0; i < N; i++) {
			int t1 = in.nextInt();
			int t2 = in.nextInt();
			max = Math.max(max, t2 - t1);
		}
		System.out.println(max);
	}


}
