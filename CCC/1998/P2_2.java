package ccc_1998;

public class P2_2 {

	public static void main(String[] args) {
		for (int i = 100; i <= 999; i++) {
			int sum = 0;
			int num = i;
			
			while (num > 0) {
				int digit = num % 10;
				num /= 10;
				sum += Math.pow(digit, 3);
			}
			
			if (sum == i) {
				System.out.println(sum);
			}
		}
	}

}
