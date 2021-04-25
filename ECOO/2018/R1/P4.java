package ECOO;
import java.util.Scanner;

public class ECOO_2018_R1_P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int X = in.nextInt();
			int Y = in.nextInt();
			
			long xLow = 0;
			long xHigh = 1;
			long yLow = -1;
			long yHigh = 0;
			
			int j = 1;
			for (; X < xLow || X > xHigh || Y < yLow || Y > yHigh; j++) {
				switch (j & 3) {
				case 0:
					yLow -= xHigh - xLow;
					break;
				case 1:
					xLow -= yHigh - yLow;
					break;
				case 2:
					yHigh += xHigh - xLow;
					break;
				case 3:
					xHigh += yHigh - yLow;
					break;
				}
			}
			System.out.println(j);
		}
	}

}
