package DMOJ;
import java.util.StringTokenizer;
import java.io.*;

public class Binary_Indexed_Tree_Test {
	
	static class BITree {
		long[] BITree;
		
		BITree(int size) {
			BITree = new long[size + 1];
		}
		
		long sum(int x) {
			long sum = 0;
			for (; x > 0; x -= x & -x) {
				sum += BITree[x];
			}
			return sum;
		}
		
		long sum(int l, int r) {
			return sum(r) - sum(l - 1);
		}
		
		void update(int x, int v) {
			for (; x < BITree.length; x += x & -x) {
				BITree[x] += v;
			}
		}
	}
	
	static final int MAXN = 100001;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer NM = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(NM.nextToken());
		int M = Integer.parseInt(NM.nextToken());
		
		BITree sum = new BITree(N);
		BITree cnt = new BITree(MAXN);
		
		int[] arr = new int[N + 1];
		StringTokenizer a = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			arr[i] = Integer.parseInt(a.nextToken());
			sum.update(i, arr[i]);
			cnt.update(arr[i], 1);
		}

		int x, v, l, r;
		for (int i = 0; i < M; i++) {
			StringTokenizer q = new StringTokenizer(br.readLine());
			char oper = q.nextToken().charAt(0);
			switch (oper) {
			case 'C':
				x = Integer.parseInt(q.nextToken());
				v = Integer.parseInt(q.nextToken());

				sum.update(x, v - arr[x]);
				cnt.update(arr[x], -1);
				cnt.update(arr[x] = v, 1);
				break;
			case 'S':
				l = Integer.parseInt(q.nextToken());
				r = Integer.parseInt(q.nextToken());
				
				System.out.println(sum.sum(l, r));
				break;
			case 'Q':
				v = Integer.parseInt(q.nextToken());
				
				System.out.println(cnt.sum(v));
				break;
			}
		}
	}

}
