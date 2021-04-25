package ccc_2007;
import java.util.Scanner;

public class S3 {

	static int[] friends = new int[10000];
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			friends[x] = y;
		}
		
		while (true) {
			int s1 = in.nextInt();
			int s2 = in.nextInt();
			if (s1 == 0 && s2 == 0) {
				return;
			}
			System.out.println(separation(s1, s2));
		}
	}	
	
	private static String separation(int s1, int s2) {
		boolean[] visited = new boolean[10000];
		int degree = -1;
		
		while (!visited[s1] && s1 != s2) {
			visited[s1] = true;
			s1 = friends[s1];
			degree++;
		}
		return s1 == s2 ? "Yes " + degree : "No";
	}

}
