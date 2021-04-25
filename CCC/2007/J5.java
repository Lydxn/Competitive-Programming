package ccc_2007;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class J5 {
	
	static int size = 14;
	static int A, B;
	static List<Integer> motels = new ArrayList<Integer>(Arrays.asList(0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000));
	static long[] cache = new long[7001];
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		A = in.nextInt();
		B = in.nextInt();
		int N = in.nextInt();

		for (int i = 0; i < N; i++) {
			motels.add(in.nextInt());
		}
		size += N;

		System.out.println(paths(0));
	}
	
	public static long paths(int dist) {
		if (dist == 7000) {
			return cache[dist] = 1;
		} else if (cache[dist] > 0) {
			return cache[dist];
		} else {
			for (int i = 0; i < size; i++) {
				int motel = motels.get(i);
				if (A <= motel - dist && motel - dist <= B) {
					cache[dist] += paths(motel);
				}
			}
			return cache[dist];
		}
	}

}
