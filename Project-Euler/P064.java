package euler100;

public class P064 {

	public static void main(String[] args) {
		int odds = 4;
		for (int i = 14; i <= 10000; i++) {
			if ((seqLen(i) & 1) == 1) {
				odds++;
			}
		}
		System.out.println(odds);
	}
	
	private static int seqLen(int n) {
		int a0 = (int) Math.sqrt(n);
		if (a0 * a0 == n) {
			return 0;
		}
		
		int m = 0;
		int d = 1;
		int a = a0;
		int period = 0;
		
		do {
			m = d * a - m;
			d = (n - m * m) / d;
			a = (a0 + m) / d;
			period++;
		} while (a != a0 << 1);
		return period;
	}
	
}
