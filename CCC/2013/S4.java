package ccc_2013;
import java.util.*;
import java.io.*;

public class S4 {
	
	static Map<Integer, ArrayList<Integer>> comparisons = new HashMap<Integer, ArrayList<Integer>>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer NM = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(NM.nextToken());
		int M = Integer.parseInt(NM.nextToken());

		for (int i = 0; i < N; i++) {
			comparisons.put(i, new ArrayList<Integer>());
		}
		
		for (int i = 0; i < M; i++) {
		    StringTokenizer c = new StringTokenizer(br.readLine());
			comparisons.get(Integer.parseInt(c.nextToken()) - 1).add(Integer.parseInt(c.nextToken()) - 1);
		}
		
		StringTokenizer pq = new StringTokenizer(br.readLine());
		int p = Integer.parseInt(pq.nextToken()) - 1;
		int q = Integer.parseInt(pq.nextToken()) - 1;

		System.out.println(isTaller(p, q) ? "yes" : (isTaller(q, p) ? "no" : "unknown"));
	}
	
	private static boolean isTaller(int p, int q) {
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] visited = new boolean[comparisons.size()];
		
		queue.offer(p);
		visited[p] = true;
		
		while (!queue.isEmpty()) {
			int start = queue.poll();
			if (start == q) {
				return true;
			}
			
			for (int i : comparisons.get(start)) {
				if (!visited[i]) {
					queue.offer(i);
					visited[i] = true;
				}
			}
		}
		return false;
	}

}

