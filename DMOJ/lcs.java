package DMOJ;
import java.util.Arrays;
import java.util.Scanner;

public class Longest_Common_Subsequence {
	
	static int[] nArr, mArr;
	static int[][] cache;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		
		nArr = new int[N];
		mArr = new int[M];
		cache = new int[N + 1][M + 1];
		
		for (int i = 0; i < nArr.length; i++) {
			nArr[i] = in.nextInt();
		}
		
		for (int i = 0; i < mArr.length; i++) {
			mArr[i] = in.nextInt();
		}
		
		for (int i = 0; i < cache.length; i++) {
			Arrays.fill(cache[i], -1);
		}
		System.out.println(LCS(nArr.length, mArr.length));
	}
	
	private static int LCS(int nLen, int mLen) {
		if (nLen == 0 || mLen == 0) {
			return 0;
		} else if (cache[nLen][mLen] != -1) {
			return cache[nLen][mLen];
		} else if (nArr[nLen - 1] == mArr[mLen - 1]) {
			return cache[nLen][mLen] = 1 + LCS(nLen - 1, mLen - 1);
		} else {
			return cache[nLen][mLen] = Math.max(LCS(nLen - 1, mLen), LCS(nLen, mLen - 1));
		}
	}
	
}