package DMOJ;
import java.io.*;
import java.util.*;

public class Inaho_XI {
	
	static int MOD = 1000000007;

	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer NM = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(NM.nextToken());
		int M = Integer.parseInt(NM.nextToken());
		
		int[][] borders = new int[2][N];
		Arrays.fill(borders[0], Integer.MAX_VALUE);
		Arrays.fill(borders[1], Integer.MIN_VALUE);
		
		for (int i = 0; i < M; i++) {
		    StringTokenizer point = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				int a = Integer.parseInt(point.nextToken());
				borders[0][j] = Math.min(borders[0][j], a);
				borders[1][j] = Math.max(borders[1][j], a);
			}
		}

		long[] dists = new long[N];
		for (int i = 0; i < dists.length; i++) {
			dists[i] = borders[1][i] - borders[0][i];
		}

		long surfaceArea = 0;
		for (int i = 0; i < N; i++) {
			long side = 1;
			for (int j = 0; j < N; j++) {
				if ((i ^ j) != 0) {
					side = (side * dists[j]) % MOD;
				}
			}
			surfaceArea += side;
		}
		System.out.println(surfaceArea * 2 % MOD);
	}
	
}