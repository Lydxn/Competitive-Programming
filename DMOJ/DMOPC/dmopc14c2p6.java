import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

public class DMOPC_2014_C2_P6 {

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

	static class BITree {
		int[] BITree;

		BITree(int size) {
			BITree = new int[size + 1];
		}

		int sum(int x) {
			int sum = 0;
			for (; x > 0; x -= x & -x) {
				sum += BITree[x];
			}
			return sum;
		}

		int sum(int l, int r) {
			return sum(r + 1) - sum(l);
		}

		void update(int x, int v) {
			for (; x < BITree.length; x += x & -x) {
				BITree[x] += v;
			}
		}
	}

	static class Pair implements Comparable<Pair> {
		int first, second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}

		@Override
		public int compareTo(Pair o) {
			return o.first - first;
		}
	}

	static class Query implements Comparable<Query> {
		int a, b, q, idx;
		public Query(int a, int b, int q, int idx) {
			this.a = a;
			this.b = b;
			this.q = q;
			this.idx = idx;
		}

		@Override
		public int compareTo(Query o) {
			return o.q - q;
		}
	}

	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		int N = in.nextInt();

		Pair[] m = new Pair[N];
		for (int i = 0; i < m.length; i++) {
			m[i] = new Pair(in.nextInt(), i + 1);
		}
		Arrays.sort(m);

		int Q = in.nextInt();
		Query[] queries = new Query[Q];
		for (int i = 0; i < queries.length; i++) {
			queries[i] = new Query(in.nextInt(), in.nextInt(), in.nextInt(), i);
		}
		Arrays.sort(queries);

		int[] res = new int[Q];
		BITree bit = new BITree(N);

		for (int i = 0, idx = 0; i < queries.length; i++) {
			while (idx < N && m[idx].first >= queries[i].q) {
				bit.update(m[idx].second, m[idx++].first);
			}
			res[queries[i].idx] = bit.sum(queries[i].a, queries[i].b);
		}

		for (int r : res) {
			System.out.println(r);
		}
	}

}
