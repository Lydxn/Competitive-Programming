import java.io.*;
import java.util.*;

class Sequence {
	int R;
	int P;
	String W;

	public Sequence(int R, int P, String W) {
		this.R = R;
		this.P = P;
		this.W = W;
	}
}

public class P5 {

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

	public static void main(String[] args) throws IOException {
		Reader in = new Reader();

		for (int i = 0; i < 5; i++) {
			int W = in.nextInt();
			int C = in.nextInt();
			int R = in.nextInt();

			char[][] dam = new char[R][C];
			for (int j = 0; j < dam.length; j++) {
				dam[j] = in.readLine().toCharArray();
			}

			int res = 0;
			for (int j = 0; j < W; j++) {
				int r = 0;
				int c = 0;

				while (true) {
					if (r != R - 1 && dam[r + 1][c] != '#') {
						r++;
					} else if (c != C - 1 && dam[r][c + 1] != '#') {
						c++;
					} else {
						break;
					}
				}

				if (dam[r][c] == 'A') {
					res++;
				}
				dam[r][c] = '#';
			}
			System.out.println(res);
		}
	}

}
