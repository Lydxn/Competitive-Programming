package euler100;

public class P002 {

	public static void main(String[] args) {
		long a = 2;
		long b = 8;
		long sum = a + b;

		while (b <= 4000000) {
			long c = 4 * b + a;
			if (c > 4000000) {
				break;
			}
			
			a = b;
			b = c;
			sum += b;
		}
		
		System.out.println(sum);
	}

}
