import java.util.*;

public class DMOPC_2014_C5_P4 {

	static class Node implements Comparable<Node> {
		int node;
		double cost;

		public Node(int node, double cost) {
			this.node = node;
			this.cost = cost;
		}

		@Override
		public int compareTo(Node o) {
			return Double.compare(cost, o.cost);
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int V = in.nextInt();
		int E = in.nextInt();

		@SuppressWarnings("unchecked")
		List<Node>[] adj = new ArrayList[V + 1];
		for (int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Node>();
		}

		for (int i = 0; i < E; i++) {
			int m = in.nextInt(), n = in.nextInt(), d = in.nextInt(), s = in.nextInt();
			adj[m].add(new Node(n, (double) d / s * 60));
			adj[n].add(new Node(m, (double) d / s * 60));
		}

		Queue<Node> pq = new PriorityQueue<Node>();
		double[] dist = new double[V + 1];
		int[] len = new int[V + 1];

		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[1] = 0;
		pq.add(new Node(1, 0));

		while (!pq.isEmpty()) {
			Node curr = pq.poll();
			for (Node n : adj[curr.node]) {
				double newDist = dist[curr.node] + n.cost;
				if (newDist < dist[n.node] || (newDist == dist[n.node] && len[curr.node] + 1 <= len[n.node])) {
					dist[n.node] = newDist;
					len[n.node] = len[curr.node] + 1;
					pq.add(new Node(n.node, dist[n.node]));
				}
			}
		}
		System.out.println(len[V] + "\n" + Math.round(dist[V] / 3));
	}

}
