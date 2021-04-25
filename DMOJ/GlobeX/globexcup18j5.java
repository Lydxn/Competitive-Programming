import java.io.*;
import java.util.*;

public class Main {
    static List<Integer>[] city;
	static int[] level;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer nmqc = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(nmqc.nextToken());
		int M = Integer.parseInt(nmqc.nextToken());
		int Q = Integer.parseInt(nmqc.nextToken());
		int C = Integer.parseInt(nmqc.nextToken());
		

		city = new ArrayList[N + 1];
		level = new int[N + 1];
		Arrays.fill(level, Integer.MAX_VALUE);
		
		for (int i = 0; i < city.length; i++) {
			city[i] = new ArrayList<Integer>();
		}
		
		for (int i = 0; i < M; i++) {
		    StringTokenizer path = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(path.nextToken());
			int v = Integer.parseInt(path.nextToken());

			city[u].add(v);
			city[v].add(u);
		}
		
		shortestPath(C);
		for (int i = 0; i < Q; i++) {
		    StringTokenizer deliver = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(deliver.nextToken());
			int b = Integer.parseInt(deliver.nextToken());
			
			System.out.println(level[a] == Integer.MAX_VALUE || level[b] == Integer.MAX_VALUE ? "This is a scam!" : level[a] + level[b]);
		}
	}
	
	private static void shortestPath(int C) {
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] visited = new boolean[city.length + 1];

		queue.offer(C);
		visited[C] = true;
		level[C] = 0;
		
		while (!queue.isEmpty()) {
			int start = queue.poll();
			
			for (int i : city[start]) {
				if (!visited[i]) {
					visited[i] = true;
					level[i] = level[start] + 1;
					queue.add(i);
				}
			}
		}
	}
}
