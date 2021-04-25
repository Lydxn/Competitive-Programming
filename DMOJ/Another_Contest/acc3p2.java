package DMOJ.Another_Contest;
import java.io.*;
import java.util.Arrays;

public class Another_Contest_3_P2 {
	
	static class King {
		int x;
		int y;
		
		public King(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
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
  
        public String readLine() throws IOException { 
            byte[] buf = new byte[64];
            int cnt = 0, c; 
            while ((c = read()) != -1) { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
            return neg ? -ret : ret;
        } 
  
        public long nextLong() throws IOException { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } while ((c = read()) >= '0' && c <= '9'); 
            return neg ? -ret : ret;
        } 
  
        public double nextDouble() throws IOException {
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.')
                while ((c = read()) >= '0' && c <= '9')
                    ret += (c - '0') / (div *= 10); 
            
            return neg ? -ret : ret;
        } 
  
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException {
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
		int N = in.nextInt();
		
		King[] kings = new King[N];
		int[] rotX = new int[N];
		int[] rotY = new int[N];
		
		for (int i = 0; i < N; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			
			kings[i] = new King(x, y);
			rotX[i] = x - y;
			rotY[i] = x + y;
		}
		
		Arrays.sort(rotX);
		Arrays.sort(rotY);
		
		long medX = rotX[N / 2];
		long medY = rotY[N / 2];
		long X = (medX + medY) / 2;
		long Y = (medY - medX) / 2;
		
		long res = Long.MAX_VALUE;
		for (long x = X - 1; x <= X + 1; x++) {
			for (long y = Y - 1; y <= Y + 1; y++) {
				long poss = 0;
				for (King k : kings) {
					poss += Math.max(Math.abs(k.x - x), Math.abs(k.y - y));
				}
				res = Math.min(res, poss);
			}
		}
		System.out.println(res);
	}

}
