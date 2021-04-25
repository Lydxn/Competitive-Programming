package ccc_2005;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter lower limit of range");
		int lower = in.nextInt();
		System.out.println("Enter upper limit of range");
		int upper = in.nextInt();
		
		int factors = 0;
		int RSA = 0;
		
		for (int i = lower; i <= upper; i++) {
			for (int j = 1; j <= i; j++) {
				if (i % j == 0) {
					factors++;
				}
			}
			
			if (factors == 4) {
				RSA++;
			}
			factors = 0;
		}
		System.out.println(RSA);
	}

}
