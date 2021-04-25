package ccc_2018;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int spaces = in.nextInt();
		in.nextLine();
		String yesterday = in.nextLine();
		String today = in.nextLine();
		
		int cars = 0;
		
		for (int i = 0; i < spaces; i++) {
			if (yesterday.charAt(i) == 'C' && today.charAt(i) == 'C') {
				cars++;
			}
		}
		System.out.println(cars);
	}

}
