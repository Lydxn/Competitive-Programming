package euler100;
import java.util.LinkedList;

public class P003 {

	public static void main(String[] args) {
		long n = 600851475143L;
		
		LinkedList<Long> factors = new LinkedList<Long>();
		for (long i = 2; i <= n; i++) {
			while (n % i == 0) {
				factors.add(i);
				n /= i;
			}
		}
		System.out.println(factors.get(factors.size() - 1));
	}

}
