package ccc_2005;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int c = in.nextInt();
		int r = in.nextInt();

		int fX = 0;
		int fY = 0;
		while (true) {
			int rX = in.nextInt();
			int rY = in.nextInt();
			if (rX == 0 && rY == 0) {
				return;
			}
			
			fX = fX + rX < 0 ? 0 : (fX + rX > c ? c : fX + rX);
			fY = fY + rY < 0 ? 0 : (fY + rY > r ? r : fY + rY);
			System.out.println(fX + " " + fY);
		}
	}

}
