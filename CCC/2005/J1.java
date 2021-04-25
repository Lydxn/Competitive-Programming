package ccc_2005;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Number of daytime minutes?");
		int daytime = in.nextInt();
		System.out.println("Number of evening minutes?");
		int evening = in.nextInt();
		System.out.println("Number of weekend minutes?");
		int weekend = in.nextInt();
		
		float planA, planB;
		
		if (daytime > 100) {
			planA = (float) ((daytime - 100) * 0.25 + evening * 0.15 + weekend * 0.20);
		} else {
			planA = (float) (evening * 0.15 + weekend * 0.20);
		}
		
		if (daytime > 250) {
			planB = (float) ((daytime - 250) * 0.45 + evening * 0.35 + weekend * 0.25);
		} else {
			planB = (float) (evening * 0.35 + weekend * 0.25);
		}
		
		System.out.println("Plan A costs " + planA);
		System.out.println("Plan B costs " + planB);
		
		if (Math.abs(planA - planB) < 0.00005) {
			System.out.println("Plan A and B are the same price.");
		} else if (planA > planB) {
			System.out.println("Plan B is cheapest.");
		} else {
			System.out.println("Plan A is cheapest.");
		}
	}

}
