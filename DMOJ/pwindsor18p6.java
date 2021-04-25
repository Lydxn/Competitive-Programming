package DMOJ;
import java.util.*;

public class You_Cant_Write_Science_Fiction_Better_Than_This {
	
	static List<Integer>[] school;
	static int N;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		int M = in.nextInt();
		int A = in.nextInt() - 1;
		int B = in.nextInt() - 1;
		
		school = new ArrayList[N];
		for (int i = 0; i < school.length; i++) {
			school[i] = new ArrayList<Integer>();
		}
		
		for (int i = 0; i < M; i++) {
			int V1 = in.nextInt() - 1;
			int V2 = in.nextInt() - 1;
			
			school[V1].add(V2);
			school[V2].add(V1);
		}
		
		int res = bfs(0, A) + bfs(A, B);
		System.out.println(res < 0 ? -1 : res);
	}
	
	private static int bfs(int start, int dest) {
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] visited = new boolean[N];
		int[] dist = new int[N];
		
		queue.offer(start);
		visited[start] = true;
		dist[start] = 0;
		
		while (!queue.isEmpty()) {
			int curr = queue.poll();
			for (int s : school[curr]) {
				if (!visited[s]) {
					visited[s] = true;
					queue.add(s);
					dist[s] = dist[curr] + 1;
				}
				
				if (s == dest) {
					return dist[s];
				}
			}
		}
		return -1;
	}
	
}