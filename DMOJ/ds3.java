package DMOJ;
import java.io.*;
import java.util.StringTokenizer;


public class Segment_Tree_Test {
	
	static class STree {
		class Node {
			int cnt = 0;
			int gcd = 0;
			int min = Integer.MAX_VALUE;
		}
		
		private static int gcd(int a, int b) {
			return b == 0 ? a : gcd(b, a % b);
		}

		Node[] STree;
		int[] arr;
		
		public STree(int[] arr) {
			STree = new Node[(1 << (int) Math.ceil(Math.log(arr.length) / Math.log(2))) << 1];
			for (int i = 0; i < STree.length; i++) {
				STree[i] = new Node();
			}
			this.arr = arr.clone();
		}
		
		void push(int idx) {
			STree[idx].cnt = 0;
			STree[idx].gcd = gcd(STree[idx << 1].gcd, STree[idx << 1 | 1].gcd);
			STree[idx].min = Math.min(STree[idx << 1].min, STree[idx << 1 | 1].min);
			
			if (STree[idx].gcd == STree[idx << 1].gcd) {
				STree[idx].cnt += STree[idx << 1].cnt;
			}
			
			if (STree[idx].gcd == STree[idx << 1 | 1].gcd) {
				STree[idx].cnt += STree[idx << 1 | 1].cnt;
			}
		}

		void build(int idx, int s, int e) {
			if (s == e) {
				STree[idx].cnt = 1;
				STree[idx].gcd = STree[idx].min = arr[s - 1];
			} else {
				int mid = (s + e) >> 1;
				build(idx << 1, s, mid);
				build(idx << 1 | 1, mid + 1, e);
				push(idx);
			}
		}
		
		void updateQ(int idx, int s, int e, int x, int v) {
			if (s <= x && e >= x) {
				if (s == x && e == x) {
					STree[idx].cnt = 1;
					STree[idx].gcd = STree[idx].min = v;
				} else {
					int mid = (s + e) >> 1;
					updateQ(idx << 1, s, mid, x, v);
					updateQ(idx << 1 | 1, mid + 1, e, x, v);
					push(idx);
				}
			}
		}
		
		int minQ(int idx, int s, int e, int l, int r) {
			if (s > r || e < l) {
				return Integer.MAX_VALUE;
			} else if (s >= l && e <= r) {
				return STree[idx].min;
			} else {
				int mid = (s + e) >> 1;
				return Math.min(minQ(idx << 1, s, mid, l, r), 
								minQ(idx << 1 | 1, mid + 1, e, l, r));
				
			}
		}
		
		int gcdQ(int idx, int s, int e, int l, int r) {
			if (s > r || e < l) {
				return 0;
			} else if (s >= l && e <= r) {
				return STree[idx].gcd;
			} else {
				int mid = (s + e) >> 1;
				return gcd(gcdQ(idx << 1, s, mid, l, r), 
						   gcdQ(idx << 1 | 1, mid + 1, e, l, r));
			}
		}

		int cntQ(int idx, int s, int e, int l, int r) {
			if (s > r || e < l) {
				return 0;
			} else if (s >= l && e <= r) {
				return STree[idx].gcd == gcdQ(1, 1, arr.length, l, r) ? STree[idx].cnt : 0;
			} else {
				int mid = (s + e) >> 1;
				return cntQ(idx << 1, s, mid, l, r) + 
					   cntQ(idx << 1 | 1, mid + 1, e, l, r);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer nmST = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(nmST.nextToken());
		int M = Integer.parseInt(nmST.nextToken());
		
		int[] arr = new int[N];
		StringTokenizer arrST = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(arrST.nextToken());
		}
		
		STree tree = new STree(arr);
		tree.build(1, 1, N);

		for (int i = 0; i < M; i++) {
			StringTokenizer qST = new StringTokenizer(br.readLine());
			char oper = qST.nextToken().charAt(0);
			int a = Integer.parseInt(qST.nextToken());
			int b = Integer.parseInt(qST.nextToken());
			
			switch (oper) {
			case 'C':
				tree.updateQ(1, 1, N, a, b);
				break;
			case 'M':
				System.out.println(tree.minQ(1, 1, N, a, b));
				break;
			case 'G':
				System.out.println(tree.gcdQ(1, 1, N, a, b));
				break;
			case 'Q':
				System.out.println(tree.cntQ(1, 1, N, a, b));
				break;
			}
		}
	}

}
