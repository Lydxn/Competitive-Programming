package DMOJ;
import java.io.*;
import java.util.*;

public class Disjoint_Set_Test {
	
	static class DSet {
		int[] DSet;
		
		public DSet(int size) {
			DSet = new int[size];
			Arrays.fill(DSet, -1);
		}
		
		int find(int i) {
			return DSet[i] < 0 ? i : (DSet[i] = find(DSet[i]));
		}
		
		boolean union(int u, int v) {
			u = find(u);
			v = find(v);
			
			if (u == v) {
				return false;
			}
			
			if (DSet[u] > DSet[v]) {
				int temp = u;
				u = v;
				v = temp;
			}
			
			DSet[u] += DSet[v];
			DSet[v] = u;
			return true;
		}
	}
	
	static final int MAXN = 100001;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer NM = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(NM.nextToken());
		int M = Integer.parseInt(NM.nextToken());
		
		DSet graph = new DSet(MAXN);
		List<Integer> res = new ArrayList<Integer>();
		
		for (int i = 0; i < M; i++) {
			StringTokenizer e = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(e.nextToken());
			int v = Integer.parseInt(e.nextToken());
			
			if (graph.union(u, v)) {
				res.add(i + 1);
			}
		}
		
		if (res.size() == N - 1) {
			for (int i : res) {
				System.out.println(i);
			}
		} else {
			System.out.println("Disconnected Graph");
		}
	}

}
