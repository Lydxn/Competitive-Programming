import java.io.*;

public class DMOPC_2015_C1_P6 {

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String read() throws IOException {
            byte[] ret = new byte[64];
            int idx = 0;
            byte c = Read();
            while (c <= ' ') {
                c = Read();
            }
            do {
                ret[idx++] = c;
                c = Read();
            } while (c != -1 && c != ' ' && c != '\n' && c != '\r');
            return new String(ret, 0, idx);
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64];
            int cnt = 0, c;
            while ((c = Read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = Read();
            while (c <= ' ')
                c = Read();
            boolean neg = (c == '-');
            if (neg)
                c = Read();
            do {
                ret = ret * 10 + c - '0';
            }  while ((c = Read()) >= '0' && c <= '9');
            return neg ? -ret : ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = Read();
            while (c <= ' ')
                c = Read();
            boolean neg = (c == '-');
            if (neg)
                c = Read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = Read()) >= '0' && c <= '9');
            return neg ? -ret : ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = Read();
            while (c <= ' ')
                c = Read();

            boolean neg = (c == '-');
            if (neg)
                c = Read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = Read()) >= '0' && c <= '9');

            if (c == '.')
                while ((c = Read()) >= '0' && c <= '9')
                    ret += (c - '0') / (div *= 10);

            return neg ? -ret : ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte Read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }

	static int[] A, tree, lazy;
	static int M;

	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		M = in.nextInt();
		int N = in.nextInt();
		int Q = in.nextInt();

		A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = in.nextInt();
		}

		tree = new int[6 * N];
		lazy = new int[12 * N];
		build(1, 1, N);

		for (int i = 0; i < Q; i++) {
			int oper = in.nextInt(), l = in.nextInt(), r = in.nextInt();
			if (oper == 1) {
				int x = in.nextInt();
				update(1, 1, N, l, r, x % M);
			} else {
				System.out.println(query(1, 1, N, l, r));
			}
		}
	}

	private static int build(int idx, int s, int e) {
		if (s == e) {
			return tree[idx] = A[s] % M;
		} else {
			int mid = (s + e) >> 1;
			return tree[idx] = add(build(idx << 1, s, mid), build(idx << 1 | 1, mid + 1, e));
		}
	}

	private static int update(int idx, int s, int e, int l, int r, int v) {
		propogate(idx, s, e);
		if (l > r) {
			return tree[idx];
		} else if (s == l && e == r) {
			lazy[idx << 1] += v;
			lazy[idx << 1 | 1] += v;
			return tree[idx] = add(tree[idx], mult(v, e - s + 1));
		} else {
			int mid = (s + e) >> 1;
			return tree[idx] = add(update(idx << 1, s, mid, l, Math.min(r, mid), v),
								   update(idx << 1 | 1, mid + 1, e, Math.max(l, mid + 1), r, v));
		}
	}

	private static int query(int idx, int s, int e, int l, int r) {
		propogate(idx, s, e);
		if (l > r) {
			return 0;
		} else if (s == l && e == r) {
			return tree[idx];
		} else {
			int mid = (s + e) >> 1;
			return add(query(idx << 1, s, mid, l, Math.min(r, mid)),
					   query(idx << 1 | 1, mid + 1, e, Math.max(l, mid + 1), r));
		}
	}

	private static void propogate(int idx, int s, int e) {
		if (lazy[idx] != 0) {
			tree[idx] = add(tree[idx], mult(lazy[idx], e - s + 1));
			lazy[idx << 1] += lazy[idx];
			lazy[idx << 1 | 1] += lazy[idx];
			lazy[idx] = 0;
		}
	}

	private static int add(int a, int b) {return (a % M + b % M) % M;}
	private static int mult(int a, int b) {return (a % M * b % M) % M;}

}
