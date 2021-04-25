package DMOJ;
import java.io.*;

public class Binary_Search_Tree_Test {
	
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
	
	static class AVLTree<Value extends Comparable<Value>> {
		class Node {
			Value v;
			int height, size;
			Node l, r;
			
			public Node(Value v) {
				this.v = v;
				this.height = 0;
				this.size = 1;
			}
		}
		
		Node root;
		
		int height(Node node) {
			return node == null ? 0 : node.height;
		}
		
		int size(Node node) {
			return node == null ? 0 : node.size;
		}
		
		int getBalance(Node node) {
			return height(node.l) - height(node.r);
		}
		
		void update(Node node) {
			node.height = Math.max(height(node.l), height(node.r)) + 1;
			node.size = size(node.l) + size(node.r) + 1;
		}
		
		Node balance(Node node) {
			int balance = getBalance(node);
			if (balance > 1) {
				if (getBalance(node.l) < 0) {
					node.l = rotateLeft(node.l);
				}
				node = rotateRight(node);
			} else if (balance < -1) {
				if (getBalance(node.r) > 0) {
					node.r = rotateRight(node.r);
				}
				node = rotateLeft(node);
			}
			
			update(node);
			return node;
		}
		
		Node min(Node node) {
			return node.l == null ? node : min(node.l);
		}
		
		Node rotateLeft(Node node) {
			Node temp = node.r;
			node.r = temp.l;
			temp.l = node;
			
			update(node);
			update(temp);
			return temp;
		
		}
		
		Node rotateRight(Node node) {
			Node temp = node.l;
			node.l = temp.r;
			temp.r = node;
			
			update(node);
			update(temp);
			return temp;
		}
		
		boolean contains(Value v) {
			return contains(root, v);
		}
		
		boolean contains(Node node, Value v) { 
			if (node == null) {
				return false;
			} else {
				int cmp = v.compareTo(node.v);
				if (cmp < 0) {
					return contains(node.l, v);
				} else if (cmp > 0) {
					return contains(node.r, v);
				} else {
					return true;
				}
			}
		}
		
		
		void insert(Value v) {
			root = insert(root, v);
		}
		
		Node insert(Node node, Value v) {
			if (node == null) {
				return new Node(v);
			} else {
				int cmp = v.compareTo(node.v);
				if (cmp < 0) {
					node.l = insert(node.l, v);
				} else {
					node.r = insert(node.r, v);
				}
				return balance(node);
			}
		}
		
		void remove(Value v) {
			if (contains(v)) {
				root = remove(root, v);
			}
		}
		
		Node remove(Node node, Value v) {
			int cmp = v.compareTo(node.v);
			if (cmp < 0) {
				node.l = remove(node.l, v);
			} else if (cmp > 0) {
				node.r = remove(node.r, v);
			} else if (node.l == null) {
				return node.r;
			} else if (node.r == null) {
				return node.l;
			} else {
				Value temp = min(node.r).v;
				node.v = temp;
				node.r = remove(node.r, temp);
			}
			return balance(node);
		}
		
		Value select(int v) {
			return select(root, v).v;
		}
		
		Node select(Node node, int v) {
			if (node == null) {
				return null;
			} else {
				int sizeL = size(node.l);
				if (sizeL > v) {
					return select(node.l, v);
				} else if (sizeL < v) {
					return select(node.r, v - sizeL - 1);
				} else {
					return node;
				}
			}
		}
		
		int rank(Value v) {
			return rank(root, v);
		}
		
		int rank(Node node, Value v) {
			if (node == null) {
				return 0;
			} else if (v.compareTo(node.v) > 0) {
				return rank(node.r, v) + size(node.l) + 1;
			} else {
				return rank(node.l, v);
			}
		}
		
		void print() {
			print(root);
			System.out.println();
		}
		
		void print(Node node) {
			if (node != null) {
				print(node.l);
				System.out.print(node.v + " ");
				print(node.r);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		Reader in = new Reader();
		int N = in.nextInt();
		int M = in.nextInt();
		
		AVLTree<Integer> tree = new AVLTree<Integer>();
		for (int i = 0; i < N; i++) {
			tree.insert(in.nextInt());
		}
		
		int prev = 0;
		for (int i = 0; i < M; i++) {
			char oper = in.read().charAt(0);
			int v = in.nextInt() ^ prev;
			
			switch (oper) {
			case 'I':
				tree.insert(v);
				break;
			case 'R':
				tree.remove(v);
				break;
			case 'S':
				System.out.println(prev = tree.select(v - 1));
				break;
			case 'L':
				System.out.println(prev = tree.contains(v) ? tree.rank(v) + 1 : -1);
				break;
			}
		}
		tree.print();
	}

}
