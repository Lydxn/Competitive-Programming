package DMOJ;
import java.util.Scanner;

public class Wow_Much_Parking_Lot {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		int x = 0;
		int y = 0;
		for (int i = 0; i < N; i++) {
			String dir = in.nextLine();
			int dist = in.nextInt();
			in.nextLine();
			
			switch (dir) {
			case "North":
				y += dist;
				break;
			case "East":
				x += dist;
				break;
			case "South":
				y -= dist;
				break;
			case "West":
				x -= dist;
				break;
			}
		}
		System.out.println(x + " " + y);
	}

}