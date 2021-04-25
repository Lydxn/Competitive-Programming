package DMOJ;
import java.util.*;

public class Single_Source_Shortest_Path {
	
	static class Node implements Comparable<Node> {
		int node;
		int weight;
		
		public Node(int node, int weight) {
			this.node = node;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Node o) {
			return Integer.compare(this.weight, o.weight);
		}
	}
	
	static int N;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		int M = in.nextInt();
		
		List<Node>[] adj = new ArrayList[N + 1];
		for (int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Node>();
		}
		
		for (int i = 0; i < M; i++) {
			int u = in.nextInt();
			int v = in.nextInt();
			int w = in.nextInt();
			
			adj[u].add(new Node(v, w));
			adj[v].add(new Node(u, w));
		}
		
		int[] dist = dijkstra(adj, 1);
		for (int i = 1; i <= N; i++) {
			System.out.println(dist[i] == Integer.MAX_VALUE ? -1 : dist[i]);
		}
	}
	
	private static int[] dijkstra(List<Node>[] adj, int src) {
		Queue<Node> pq = new PriorityQueue<Node>();
		pq.offer(new Node(src, 0));
		
		int[] dist = new int[N + 1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[src] = 0;
		
		while (!pq.isEmpty()) {
			Node curr = pq.poll();
			for (Node n : adj[curr.node]) {
				int newDist = curr.weight + n.weight;
				if (dist[n.node] > newDist) {
					dist[n.node] = newDist;
					pq.offer(new Node(n.node, dist[n.node]));
				}
			}
		}
		return dist;
	}

}
