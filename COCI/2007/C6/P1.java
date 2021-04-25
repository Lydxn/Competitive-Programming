package COCI;
import java.util.Scanner;

public class COCI_2007_C6_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int[] prices = new int[3];
		for (int i = 0; i < 3; i++) {
			prices[i] = in.nextInt();
		}
		
		int[] parking = new int[101];
		for (int j = 0; j < 3; j++) {
			parking[in.nextInt() - 1]++;
			parking[in.nextInt() - 1]--;
		}
		
		int curr = 0;
		int cost = 0;
		for (int k = 0; k <= 100; k++) {
			parking[k] += curr;
			curr = parking[k];
			switch (parking[k]) {
				case 1:
					cost += prices[0];
					break;
				case 2:
					cost += prices[1] * 2;
					break;
				case 3:
					cost += prices[2] * 3;
					break;
			}
		}
		System.out.println(cost);
	}

}
