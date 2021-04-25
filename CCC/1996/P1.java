package ccc_1996;
import java.util.Scanner;

public class P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int following = in.nextInt();
		
		for (int i = 0; i < following; i++) {
			int num = in.nextInt();
			
			if (factorSum(num) == num) {
				System.out.println(num + " is a perfect number.\n");
			} else if (factorSum(num) < num) {
				System.out.println(num + " is a deficient number.\n");
			} else {
				System.out.println(num + " is an abundant number.\n");
			}
		}
	}
	
	private static int factorSum(int n) {
		int sum = 0;
		for (int i = 1; i <= n / 2; i++) {
			if (n % i == 0) {
				sum += i;
			}
		}
		return sum;
	}

}
