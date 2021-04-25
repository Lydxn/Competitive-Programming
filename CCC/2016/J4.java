package ccc_2016;
import java.util.Scanner;

public class J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String departure = in.nextLine();
		
		int hour = Integer.parseInt(departure.substring(0, 2));
		int min = Integer.parseInt(departure.substring(3, 5));
		double distance = 0;
		
		while (distance < 120) {
			distance += (hour >= 7 && hour < 10) || (hour >= 15 && hour < 19) ? 0.5 : 1;
			min++;
			
			if (min > 59) {
				min -= 60;
				hour++;
			}
			
			if (hour > 23) {
				hour = 0;
			}
		}
		System.out.println((hour < 10 ? "0" : "") + (hour + ":") + (min < 10 ? "0" : "") + min);
	}
	
}
