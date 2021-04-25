package ccc_2002;
import java.util.Scanner;

public class S1_J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Cost of PINK tickets:");
		int pink = in.nextInt();
		System.out.println("Cost of GREEN tickets:");
		int green = in.nextInt();
		System.out.println("Cost of RED tickets:");
		int red = in.nextInt();
		System.out.println("Cost of ORANGE tickets:");
		int orange = in.nextInt();
		System.out.println("How much must be raised with ticket sales?");
		int total = in.nextInt();
		System.out.println("Combinations are");
		
		int minimum = Integer.MAX_VALUE;
		int count = 0;
		for (int p = 0; p <= total / pink; p++) {
			for (int g = 0; g <= total / green; g++) {
				for (int r = 0; r <= total / red; r++) {
					for (int o = 0; o <= total / orange; o++) {
						if (p * pink + g * green + r * red + o * orange == total) {
							if (p + g + r + o < minimum) {
								minimum = p + g + r + o;
							}
							count++;
							System.out.println("# of PINK is " + p + "   # of GREEN is " + g + "   # of RED is " + r + "   # of ORANGE is " + o);
						}
					}
				}
			}
		}
		
		System.out.println("Total combinations is " + count + ".");
		System.out.println("Minimum number of tickets to print is " + minimum + ".");
	}

}
