import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.io.*;

public class DMOPC_2013_C3_P4 {

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

	static int S, M, N;
	static char[][] ground;
	static Integer[] B;

	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		M = in.nextInt();
		N = in.nextInt();
		S  = in.nextInt();

		B = new Integer[S];

		int sum = 0;
		for (int i = 0; i < B.length; i++) {
			B[i] = in.nextInt();
			sum += B[i];
		}
		Arrays.sort(B, Collections.reverseOrder());

		ground = new char[M][N];

		int zeros = 0;
		for (int i = 0; i < M; i++) {
			ground[i] = in.readLine().toCharArray();
			for (int j = 0; j < N; j++) {
				zeros += ground[i][j] == '0' ? 1 : 0;
			}
		}
		System.out.println(sum <= zeros && canBuild(0) ? "yes" : "no");
	}

	private static boolean canBuild(int depth) {
		if (depth == S) return true;

		boolean isPatch = false;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (i + B[depth] <= M) {
					isPatch = true;
					for (int k = 0; k < B[depth]; k++) {
						if (ground[i + k][j] == '1') {
							isPatch = false;
							break;
						}
					}

					if (isPatch) {
						for (int k = 0; k < B[depth]; k++) ground[i + k][j] = '1';
						if (canBuild(depth + 1)) return true;
						for (int k = 0; k < B[depth]; k++) ground[i + k][j] = '0';
					}
				}

				if (j + B[depth] <= N) {
					isPatch = true;
					for (int k = 0; k < B[depth]; k++) {
						if (ground[i][j + k] == '1') {
							isPatch = false;
							break;
						}
					}

					if (isPatch) {
						for (int k = 0; k < B[depth]; k++) ground[i][j + k] = '1';
						if (canBuild(depth + 1)) return true;
						for (int k = 0; k < B[depth]; k++) ground[i][j + k] = '0';
					}
				}
			}
		}
		return false;
	}

}
