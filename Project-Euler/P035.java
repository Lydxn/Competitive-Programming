package euler100;

public class P035 {
	
	public static void main(String[] args) {
		int circular = 13;
		for (int i = 101; i < 1000000; i += 2) {
			if (i % 10 != 5 && isCircularPrime(i)) {
				circular++;
			}
		}
		System.out.println(circular);
	}
	
	private static boolean isCircularPrime(int n) {
		String nStr = Integer.toString(n);
		for (int i = 0; i < nStr.length(); i++) {
			nStr = nStr.substring(1) + nStr.substring(0, 1);
			int N = Integer.parseInt(nStr);
			
			for (int j = 2; j <= Math.sqrt(N); j++) {
				if (N % j == 0) {
					return false;
				}
			}
		}
		return true;
	}

}
