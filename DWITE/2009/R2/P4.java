import java.util.Arrays;
import java.util.Scanner;

public class P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int N = in.nextInt();

			int[][] edges = new int[N][2];
			for (int j = 0; j < edges.length; j++) {
				edges[j][0] = in.nextInt();
				edges[j][1] = in.nextInt();
			}

			int[] dist = new int[100];
			Arrays.fill(dist, 9999);

			dist[1] = 0;
			for (int j = 0; j < dist.length; j++) {
				for (int[] e : edges) {
					dist[e[0]] = Math.min(dist[e[0]], dist[e[1]] + 1);
					dist[e[1]] = Math.min(dist[e[1]], dist[e[0]] + 1);
				}
			}

			int count = 0;
			for (int[] e : edges) {
				if (dist[e[0]] != -1 && dist[e[0]] == dist[e[1]]) {
					count++;
				}
			}
			System.out.println(count);
		}
	}

}
