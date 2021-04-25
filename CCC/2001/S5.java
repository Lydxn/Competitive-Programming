package ccc_2001;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class S5 {
	
	static String[] A, B;
	static List<Integer> res = new ArrayList<Integer>();
	static int m, n;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		m = in.nextInt();
		n = in.nextInt();
		in.nextLine();
		
		A = new String[n];
		B = new String[n];
		for (int i = 0; i < n; i++) A[i] = in.nextLine();
		for (int i = 0; i < n; i++) B[i] = in.nextLine();
		
		if (solve(0, "", "")) {
			System.out.println(res.size());
			for (int i : res) {
				System.out.println(i);
			}
		} else {
			System.out.println("No solution.");
		}
	}
	
	private static boolean solve(int k, String a, String b) {
		int aLen = a.length(), bLen = b.length(), minLen = Math.min(aLen, bLen);
		if (!a.substring(0, minLen).equals(b.substring(0, minLen)) || k == m) return false;
		if (k > 0 && aLen == bLen) return true;

		for (int i = 0; i < n; i++) {
			if (solve(k + 1, a + A[i], b + B[i])) {
				res.add(0, i + 1);
				return true;
			}
		}
		return false;
	}

}
