package ccc_2011;
import java.util.Scanner;

public class S3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int m = in.nextInt();
			int x = in.nextInt();
			int y = in.nextInt();
			
			System.out.println(isCrystal(m, x, y) == true ? "crystal" : "empty");
		}
	}
	
	private static boolean isCrystal(int m, int x, int y) {
		int secX = (int) (x / Math.pow(5, m - 1));
		int secY = (int) (y / Math.pow(5, m - 1));
		
		if ((secX > 0 && secX < 4 && secY == 0) || (secX == 2 && secY == 1)) {
			return true;
		} else if (((secX == 1 || secX == 3) && secY == 1) || (secX == 2 && secY == 2)) {
			return isCrystal(m - 1, (int) (x % Math.pow(5, m - 1)), (int) (y % Math.pow(5, m - 1)));
		}
		return false;
	}

}
