package ccc_2007;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		int[] briefcase = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
		for (int i = 0; i < n; i++) {
			int value = in.nextInt();
			briefcase[value - 1] = 0;
		}
		
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			sum += briefcase[j];
		}
		int avg = sum / (10 - n);
		
		int offer = in.nextInt();
		System.out.println(offer > avg ? "deal" : "no deal");
	}

}
