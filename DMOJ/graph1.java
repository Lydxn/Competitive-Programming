package DMOJ;
import java.util.*;

public class Breaking_The_Friend_Chain {

	static List<Integer>[] people;
	static int N, M;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		M = in.nextInt();
		
		people = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			people[i] = new ArrayList<Integer>();
		}
		
		for (int i = 0; i < M; i++) {
			int A = in.nextInt() - 1;
			int B = in.nextInt() - 1;
			
			people[A].add(B);
			people[B].add(A);
		}
		
		int X = in.nextInt() - 1;
		int Y = in.nextInt() - 1;
		System.out.println(minDisable(X, Y));
	}
	
	private static int minDisable(int X, int Y) {
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] visited = new boolean[N];
		
		queue.offer(X);
		visited[X] = true;
		
		while (!queue.isEmpty()) {
			int start = queue.poll();
			for (int i : people[start]) {
				if (!visited[i]) {
					visited[i] = true;
					queue.add(i);
				}
			}
		}
		return visited[Y] ? 1 : 0;
	}

}