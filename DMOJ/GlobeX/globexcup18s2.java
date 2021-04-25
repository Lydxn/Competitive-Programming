import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		int K = in.nextInt();
		
		long hours = 0;
		long mark = 0;
		long max = (long) N * K;
		
		int[][] tests = new int[N][2];
		for (int i = 0; i < tests.length; i++) {
			tests[i][0] = in.nextInt(); 
			tests[i][1] = in.nextInt();
			mark += tests[i][0];
		}
		
		Arrays.sort(tests, new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[1], o2[1]);
			}
		});
		
		if (mark > max) {
			System.out.println(0);
			return;
		}
		
		for (int i = 0; i < tests.length && mark != max; i++) {
			long diff = Math.min(M - tests[i][0], max - mark);
			hours += diff * tests[i][1];
			mark += diff;
		}
		System.out.println(hours);
	}

}
