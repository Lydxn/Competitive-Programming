package ccc_1998;

public class P2_1 {

	public static void main(String[] args) {
		for (int i = 1000; i <= 9999; i++) {
			int sum = 0;
			for (int j = 1; j <= i / 2; j++) {
				if (i % j == 0) {
					sum += j;
				}
			}
			
			if (sum == i) {
				System.out.println(sum);
			}
		}
	}

}
