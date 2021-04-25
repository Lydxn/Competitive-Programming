package euler100;
import java.util.ArrayList;

public class P023 {

	public static void main(String[] args) {
		int max = 28123;
		ArrayList<Integer> abundants = new ArrayList<Integer>();
		boolean[] sumAbundants = new boolean[max + 1];
		
		for (int i = 12; i <= max; i++) {
			if (abundant(i)) {
				abundants.add(i);
			}
		}
		
		for (int i = 0; i < abundants.size(); i++) {
			for (int j = i; j < abundants.size(); j++) {
				int sum = abundants.get(i) + abundants.get(j);
				if (sum <= max) {
					sumAbundants[sum] = true;
				} 
			}
		}
		
		int sum = 0;
		for (int i = 1; i <= max; i++) {
			if (!sumAbundants[i]) {
				sum += i;
			}
		}
		System.out.println(sum);
	}
	
	private static boolean abundant(int n) {
		int sum = 1;
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				sum += i + n / i;
				if (i * i == n) {
					sum -= i;
				}
			}
		}
		return sum > n;
	}
	
}
