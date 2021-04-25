package COCI;
import java.util.Scanner;

public class COCI_2006_C5_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String[] current = in.nextLine().split(":");
		String[] explosion = in.nextLine().split(":");
		
		int hr = Integer.parseInt(explosion[0]) - Integer.parseInt(current[0]);
		int min = Integer.parseInt(explosion[1]) - Integer.parseInt(current[1]);
		int sec = Integer.parseInt(explosion[2]) - Integer.parseInt(current[2]);
		
		if (sec < 0) {
			sec += 60;
			min--;
		}
		
		if (min < 0) {
			min += 60;
			hr--;
		}
		
		if (hr < 0) {
			hr += 24;
		}
		
		if (hr == 0 && min == 0 & sec == 0) {
			hr = 24;
		}
		System.out.printf("%02d:%02d:%02d", hr, min, sec);
	}

}
