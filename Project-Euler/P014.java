package euler100;

public class P014 {
	
	static long[] cache = new long[1000001];
	
	public static void main(String[] args) {	
		int max = 0;
		int maxI = 0;
		for (int i = 3; i < 1000000; i++) {
			if (collatz(i) > max) {
				max = collatz(i);
				maxI = i;
			}
		}
		System.out.println(maxI);
	}
	
	private static int collatz(long n) {
		long N = n;
		int chain = 0;
		
		while (N > 1) {
			if ((N & 1) == 0) {
				N >>= 1;
				chain++;
			} else {
				N = (3 * N + 1) >> 1;
				chain += 2;
			}
		}
		return chain;
	}
	
}
