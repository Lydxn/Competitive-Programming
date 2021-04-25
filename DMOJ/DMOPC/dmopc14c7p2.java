import java.util.Scanner;

public class DMOPC_2014_C8_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] readings = new int[N];
		int max = 0, min = Integer.MAX_VALUE;

		for (int i = 0; i < readings.length; i++) {
			readings[i] = in.nextInt();
			max = Math.max(max, readings[i]);
			min = Math.min(min, readings[i]);
		}

		boolean increasing = false;
		for (int i = 0; i < readings.length; i++) {
			if (increasing && readings[i - 1] >= readings[i]) {
				System.out.println("unknown");
				return;
			}

			if (readings[i] == min) increasing = true;
			else if (readings[i] == max) {
				if (!increasing) {
					System.out.println("unknown");
					return;
				}
				increasing = false;
			}
		}
		System.out.println(max - min);
	}

}
