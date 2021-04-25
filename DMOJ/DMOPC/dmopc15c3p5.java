import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DMOPC_2015_C3_P5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();

		int[] particles = new int[N + M];
		for (int i = 0; i < particles.length; i++) {
			particles[i] = in.nextInt();
		}

		Map<Long, Long> map = new HashMap<Long, Long>();

		int size1 = particles.length / 2;
		int size2 = particles.length - size1;

		for (int i = 0; i < 1 << size1; i++) {
			long sum = 0;
			for (int j = 0; j < size1; j++) {
				if ((i & 1 << j) > 0) {
					sum += j < N ? particles[j] : -particles[j];
				}
			}
			map.put(sum, map.containsKey(sum) ? map.get(sum) + 1 : 1);
		}

		long res = 0;
		for (int i = 0; i < 1 << size2; i++) {
			long sum = 0;
			for (int j = 0; j < size2; j++) {
				if ((i & 1 << j) > 0) {
					sum += size1 + j < N ? particles[size1 + j] : -particles[size1 + j];
				}
			}

			if (map.containsKey(-sum)) {
				res += map.get(-sum);
			}
		}
		System.out.println(res - 1);
	}

}
