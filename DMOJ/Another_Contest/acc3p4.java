package DMOJ.Another_Contest;
import java.io.*;
import java.util.StringTokenizer;

public class Another_Contest_3_P4 {
	
	static class STree {
		class Node {
			int l1, l2, sum;
		}
		
		Node[] STree;
		
		STree(int size) {
			STree = new Node[(1 << (int) Math.ceil(Math.log(size) / Math.log(2))) << 1];
			for (int i = 0; i < STree.length; i++) {
				STree[i] = new Node();
			}
		}

		void propogate(int idx, int s, int e) {
			if (STree[idx].l1 != 0) {
				int len = e - s + 1;
				STree[idx].sum += STree[idx].l2 + (len + 1) * (len >> 1) * STree[idx].l1;
				
				if (s != e) {
					int mid = (s + e) >> 1;
					STree[idx << 1].l1 += STree[idx].l1;
					STree[idx << 1 | 1].l1 += STree[idx].l1;
					
					STree[idx << 1].l2 += STree[idx].l2;
					STree[idx << 1 | 1].l2 += STree[idx].l2 + (mid - s + 1) * STree[idx].l1;
				}
				STree[idx].l1 = STree[idx].l2 = 0;
			}
		}
		
		void update(int idx, int s, int e, int l, int r, int a) {
			propogate(idx, s, e);
			if (s <= r && e >= l) {
				int mid = (s + e) >> 1;
				if (s >= l && e <= r) {
					STree[idx].l1 += a;
					STree[idx].l2 += (mid - l + 1) * a;
					propogate(idx, s, e);
				} else {
					update(idx << 1, s, mid, l, r, a);
					update(idx << 1 | 1, mid + 1, e, l, r, a);
					STree[idx].sum = STree[idx << 1].sum + STree[idx << 1 | 1].sum;
				}
			}
		}
		
		int sum(int idx, int s, int e, int l, int r) {
			propogate(idx, s, e);
			if (s > r || e < l) {
				return 0;
			} else if (s >= l && e <= r) {
				return STree[idx].sum;
			} else {
				int mid = (s + e) >> 1;
				return sum(idx << 1, s, mid, l, r) +
					   sum(idx << 1 | 1, mid + 1, e, l, r);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer NQ = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(NQ.nextToken());
		int Q = Integer.parseInt(NQ.nextToken());
		
		STree tree = new STree(N);
		for (int i = 0; i < Q; i++) {
			StringTokenizer q = new StringTokenizer(br.readLine());
			int oper = Integer.parseInt(q.nextToken());
			int l = Integer.parseInt(q.nextToken());
			int r = Integer.parseInt(q.nextToken());
			
			if (oper == 1) {
				int a = Integer.parseInt(q.nextToken());
				tree.update(1, 1, N, l, r, a);
			} else {
				System.out.println(tree.sum(1, 1, N, l, r));
			}
		}
	}

}
