package ccc_2009;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int trout = in.nextInt();
		int pike = in.nextInt();
		int pickerel = in.nextInt();
		int total = in.nextInt();
		
		int count = 0;
		
		for (int t = 0; t <= total; t++) {
			for (int p = 0; p <= total; p++) {
				for (int c = 0; c <= total; c++) {
					if ((t > 0 || p > 0 || c > 0) && t * trout + p * pike + c * pickerel <= total) {
						System.out.println(t + " Brown Trout, " + p + " Northern Pike, " + c + " Yellow Pickerel");
						count++;
					}
				}
			}
		}
		System.out.println("Number of ways to catch fish: " + count);
	}

}
