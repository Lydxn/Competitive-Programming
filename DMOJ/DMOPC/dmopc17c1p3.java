import java.util.*;
import java.io.*;

public class dmopc17c1p3 {
    
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
	
	static class Node {
		int node;
		double weight;
		
		public Node(int node, double weight) {
			this.node = node;
			this.weight = weight;
		}
	}
	
	static double[] dist;
	static int[] len;
	static List<Node>[] adj;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		int N = in.nextInt();
		int M = in.nextInt();

		adj = new ArrayList[N];
		for (int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Node>();
		}
		
		for (int i = 0; i < M; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			int t = in.nextInt();
			
			adj[a].add(new Node(b, t == 1.0 ? 1.0 : 1e-5));
			adj[b].add(new Node(a, t == 1.0 ? 1.0 : 1e-5));
		}
		
		dist = new double[N];
		len = new int[N];
		
		BFS(0);
		System.out.println(dist[N - 1] == Double.MAX_VALUE ? -1 : (int) dist[N - 1] + " " + len[N - 1]);
	}
	
	private static void BFS(int start) {
		Queue<Integer> queue = new ArrayDeque<Integer>();
		queue.add(start);
		Arrays.fill(dist, Double.MAX_VALUE);
		dist[start] = 0;
		
		while (!queue.isEmpty()) {
			int curr = queue.poll();
			for (Node n : adj[curr]) {
				int node = n.node;
				double next = dist[curr] + n.weight;
				
				if (dist[node] > next) {
					dist[node] = next;
					len[node] = len[curr] + 1;
					queue.add(node);
				}
			}
		}
	}

}
