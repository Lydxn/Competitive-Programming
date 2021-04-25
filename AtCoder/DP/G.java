package AtCoder.DP;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Longest_Path {
	
	static List<Integer>[] graph;
	static int[] cache;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		
		graph = new ArrayList[N];
		cache = new int[N];
		
		for (int i = 0; i < N; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		
		for (int i = 0; i < M; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			graph[x].add(y);
		}
		
		int max = 0;
		for (int i = 0; i < graph.length; i++) {
			max = Math.max(max, longestPath(i));
		}
		System.out.println(max);
	}
	
	private static int longestPath(int start) {
		if (cache[start] != 0) {
			return cache[start];
		} else {
			cache[start] = 0;
			for (int g : graph[start]) {
				cache[start] = Math.max(cache[start], longestPath(g) + 1);
			}
			return cache[start];
		}
	}

}