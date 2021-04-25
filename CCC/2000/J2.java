package ccc_2000;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the lower bound of the interval:");
		int lower = in.nextInt();
		System.out.println("\nEnter the upper bound of the interval:");
		int upper = in.nextInt();
		System.out.println("\nThe number of rotatable numbers is:");
		
		int count = 0;
		for (int i = lower; i <= upper; i++) {
			String str = Integer.toString(i);
			boolean check = true;
			
			for (int j = 0; j < str.length(); j++) {
				char at1 = str.charAt(j);
				char at2 = str.charAt(str.length() - j - 1);
				if (at1 == '2' || at1 == '3' || at1 == '4' || at1 == '5' || at1 == '7' || 
				   (at1 == '0' && at2 != '0') || (at1 == '1' && at2 != '1') || 
				   (at1 == '6' && at2 != '9') || (at1 == '9' && at2 != '6') || 
				   (at1 == '8' && at2 != '8')) {
					check = false;
				} 
			}
			
			if (check) {
				count++;
			}
		}
		System.out.println(count);
	}

}
