package euler100;

public class P026 {

	public static void main(String[] args) {
		int max = 0;
		int maxI = 0;
		for (int i = 1000; i > 1; i--) {
			if (max < cycle(i)) {
				max = cycle(i);
				maxI = i;
			}
		}
		System.out.println(maxI);
	}
	
	private static int cycle(int n) {
		int[] remainders = new int[n];
		int value = 1;
		int pos = 0;
		
		while (remainders[value] == 0 && value != 0) {
			remainders[value] = pos;
			value = (value * 10) % n;
			pos++;
		}

		return pos - remainders[value];
	}
	
}
