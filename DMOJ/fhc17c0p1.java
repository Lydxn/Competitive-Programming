package DMOJ;
import java.util.Scanner;

public class Progress_Pie {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 1; i <= T; i++) {
			double P = in.nextInt() / 100.0;
			int X = in.nextInt();
			int Y = in.nextInt();
			
			System.out.println("Case #" + i + ": " + (colour(P, X, Y) ? "black" : "white"));
		}
	}
	
	private static boolean colour(double P, int X, int Y) {
		int dx = X - 50;
		int dy = Y - 50;
		
		if (dx * dx + dy * dy > 2500 || P == 0) {
			return false;
		} else if (dx == 0 || dy == 0) {
			return true;
		}
		
		double atan2 = Math.atan2(dy, dx);
		if (atan2 < 0) {
			atan2 += 2 * Math.PI;
		}
		
		double theta = 1 - atan2 / (2 * Math.PI);
		theta += theta >= 0.75 ? -0.75 : 0.25;
		
		return theta <= P;
	}
	
}