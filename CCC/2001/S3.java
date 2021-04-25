import java.util.*;

public class S3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		@SuppressWarnings("unchecked")
		List<Integer>[] adj = new ArrayList[27];
		for (int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		
		List<int[]> vertices = new ArrayList<int[]>();
		while (true) {
			char[] road = in.nextLine().toCharArray();
			if (road[0] == '*' && road[1] == '*') break;
			int a = road[0] - 'A', b = road[1] - 'A';
			
			vertices.add(new int[] {a, b});
			adj[a].add(b);
			adj[b].add(a);
		}
		
		int count = 0;
		for (int[] v : vertices) {
			Queue<Integer> queue = new ArrayDeque<Integer>();
			boolean[] visited = new boolean[27];
			
			queue.add(0);
			visited[0] = true;
			
			while (!queue.isEmpty()) {
				int curr = queue.poll();
				for (int a : adj[curr]) {
					if (visited[a] || (curr == v[0] && a == v[1]) || (curr == v[1] && a == v[0])) continue;
					else {
						queue.add(a);
						visited[a] = true;
					}
				}
			}

			if (!visited[1]) {
				System.out.println((char) (v[0] + 'A') + "" + (char) (v[1] + 'A'));
				count++;
			}
		}
		System.out.println("There are " + count + " disconnecting roads.");
	}

}
