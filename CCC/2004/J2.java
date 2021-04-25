package ccc_2004;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the current year:");
		int current = in.nextInt();
		System.out.println("Enter the future year:");
		int future = in.nextInt();
		
		int diff = future - current;
		
		for (int i = current; i <= diff + current; i += 60) {
			System.out.println("All positions change in year " + i);
		}
	}

}
