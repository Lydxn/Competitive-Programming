package ccc_2005;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		String place = " into your HOME.";
		int n = -1;
		String[] turn = new String[6];
		
		Scanner in = new Scanner(System.in);
		while (true) {
			String instWay = in.nextLine();
			n++;
			
			turn[n] = "Turn " + (instWay.equals("L") ? "RIGHT" : "LEFT") + place;
			String instStr = in.nextLine();
			
			place = " onto " + instStr + " street.";
			if (instStr.equals("SCHOOL")) {
				break;
			}
		}
		
		for (int i = 0; i <= n; i++) {
			System.out.println(turn[n - i]);
		}
	}

}
