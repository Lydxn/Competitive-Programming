package euler100;

public class P039 {

	public static void main(String[] args) {
		int max = 0;
		int maxP = 0;
		for (int p = 2; p <= 1000; p += 2) {
			int c = 0;
			for (int a = 2; a < p / 3; a++) {
				if (p * (p - 2 * a) % (2 * (p - a)) == 0) {
					c++;
				}
			}
			
			if (max < c) {
				max = c;
				maxP = p;
			}
		}
		System.out.println(maxP);
	}

}
