import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class dmopc17c1p2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		
		Map<Long, Long> map = new HashMap<Long, Long>();
        map.put(0L, 1L);
		long count = 0, sum = 0;
		for (int i = 1; i <= N; i++) {
			sum = (sum % M + in.nextInt()) % M;
			if (!map.containsKey(sum)) map.put(sum, 0L);
			count += map.get(sum);
			map.put(sum, map.get(sum) + 1);
		}
		System.out.println(count);
	}

}
