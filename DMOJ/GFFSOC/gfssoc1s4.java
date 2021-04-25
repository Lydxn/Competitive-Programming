package DMOJ;
import java.io.*;
import java.util.StringTokenizer;

public class Stalactites {
	
	static class BITree3D {
		long[][][] BITree3D;
		int sx, sy, sz;
		
		BITree3D(int sx, int sy, int sz) { 
			BITree3D = new long[sx + 1][sy + 1][sz + 1];
			this.sx = sx;
			this.sy = sy;
			this.sz = sz;
		}
		
		long sum(int X, int Y, int Z) {
			long sum = 0;
			for (int x = X; x > 0; x -= x & -x) {
				for (int y = Y; y > 0; y -= y & -y) {
					for (int z = Z; z > 0; z -= z & -z) {
						sum += BITree3D[x][y][z];
					}
				}	
			}
			return sum;
		}
		
		long sumRange(int X1, int Y1, int Z1, int X2, int Y2, int Z2) {
			--X1;
			--Y1;
			--Z1;
			
			return sum(X2, Y2, Z2) - sum(X1, Y2, Z2) - sum(X2, Y1, Z2) - sum(X2, Y2, Z1) +
				   sum(X1, Y1, Z2) + sum(X1, Y2, Z1) + sum(X2, Y1, Z1) - sum(X1, Y1, Z1);
		}
		
		void update(int X, int Y, int Z, int val) {
			for (int x = X; x <= sx; x += x & -x) {
				for (int y = Y; y <= sy; y += y & -y) {
					for (int z = Z; z <= sz; z += z & -z) {
						BITree3D[x][y][z] += val;
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int Q = Integer.parseInt(br.readLine());
		
		long sum = 0;
		BITree3D tree = new BITree3D(N, N, N);
		
		for (int i = 0; i < Q; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			char oper = st.nextToken().charAt(0);
			if (oper == 'C') {
				int X = Integer.parseInt(st.nextToken());
				int Y = Integer.parseInt(st.nextToken());
				int Z = Integer.parseInt(st.nextToken());
				int L = Integer.parseInt(st.nextToken());
				tree.update(X, Y, Z, (int) (L - tree.sumRange(X, Y, Z, X, Y, Z)));
			} else {
				int X1 = Integer.parseInt(st.nextToken());
				int Y1 = Integer.parseInt(st.nextToken());
				int Z1 = Integer.parseInt(st.nextToken());
				int X2 = Integer.parseInt(st.nextToken());
				int Y2 = Integer.parseInt(st.nextToken());
				int Z2 = Integer.parseInt(st.nextToken());
				sum += tree.sumRange(X1, Y1, Z1, X2, Y2, Z2);
			}
		}
		System.out.println(sum);
	}

}
