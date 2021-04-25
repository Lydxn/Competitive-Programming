package euler100;

public class P048 {

	public static void main(String[] args) {
		long sum = 0;
		long mod = 10000000000L;
		for (int i = 1; i <= 1000; i++) {
			long temp = i;
			for (int j = 1; j < i; j++) {
				temp *= i;
				temp %= mod;
			}
			
			sum += temp;
			sum %= mod;
		}
		System.out.println(sum);
	}

}
