package ccc_2011;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int h = in.nextInt();
		int M = in.nextInt();
		
		int t = 0;
		double alt = 1;
		
		while (t < M && alt > 0) {
			t++;
			alt = (-6 * Math.pow(t, 4)) + (h * Math.pow(t, 3)) + (2 * Math.pow(t, 2)) + t;
		}
		
		if (alt > 0) {
			System.out.println("The balloon does not touch ground in the given time.");
		} else {
			System.out.println("The balloon first touches ground at hour:\n" + t);
		}
	}

}
