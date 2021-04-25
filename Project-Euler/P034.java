package euler100;

public class P034 {

	public static void main(String[] args) {
		int[] facts = new int[10];
		for (int i = 0; i < 10; i++) {
			facts[i] = fact(i);
		}
		
		int res = 0;
		for (int j = 10; j < facts[9] * 7; j++) {
			int sum = 0;
			int num = j;
			while (num > 0) {
				int digit = num % 10;
				num /= 10;
				sum += facts[digit];
			}
			
			if (sum == j) {
				res += j;
			}
		}
		System.out.println(res);
	}
	
	private static int fact(int n) {
		int prod = 1;
		for (int i = 2; i <= n; i++) {
			prod *= i;
		}
		return prod;
	}

}
