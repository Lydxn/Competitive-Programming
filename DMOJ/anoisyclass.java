package DMOJ;
import java.util.*;

public class A_Noisy_Class {
	
	static List<Integer>[] connections;
	static boolean[] visited;
	static boolean silence = true;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		
		connections = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			connections[i] = new ArrayList<Integer>();
		}
		
		for (int i = 0; i < M; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			
			if (!connections[a].contains(b)) {
				connections[a].add(b);
			}
		}
		
		visited = new boolean[N];
		outer: for (int i = 0; i < N; i++) {
			Arrays.fill(visited, false);
			
			for (int c : connections[i]) {
				silence(c, i);
				if (silence) {
					break outer;
				}
			}
		}
		System.out.println(silence ? 'Y' : 'N');
	}
	
	private static void silence(int start, int end) {
		if (start == end) {
			silence = false;
		} else if (!visited[start]) {
			visited[start] = true;
			for (int c : connections[start]) {
				silence(c, end);
			}
		}
	}

}