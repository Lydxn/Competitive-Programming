package ccc_2012;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the speed limit: ");
		int limit = in.nextInt();
		System.out.print("Enter the recorded speed of the car: ");
		int speed = in.nextInt();
		
		if (speed <= limit) {
			System.out.println("Congratulations, you are within the speed limit!");
		} else {
			if (Math.abs(limit - speed) >= 1 && Math.abs(limit - speed) <= 20) {
				System.out.println("You are speeding and your fine is $100.");
			} else if (Math.abs(limit - speed) >= 31) {
				System.out.println("You are speeding and your fine is $500.");
			} else {
				System.out.println("You are speeding and your fine is $270.");
			}
		}
	}

}
