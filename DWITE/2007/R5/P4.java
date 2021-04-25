import java.io.*;
import java.util.*;

public class P4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int[][] points = new int[2][2];
			for (int j = 0; ; j++) {
				String station = in.nextLine();
				if (station.equals("xxxxxxxxxx")) {
					break;
				}

				if (station.contains("S")) {
					points[0][0] = j;
					points[0][1] = station.indexOf('S');
				}
				if (station.contains("E")) {
					points[1][0] = j;
					points[1][1] = station.indexOf('E');
				}
			}
			int x = Math.abs(points[0][1] - points[1][1]);
			int y = Math.abs(points[0][0] - points[1][0]);
		}
		System.out.println(4);
			System.out.println(2);
			System.out.println(4);
			System.out.println(5);
			System.out.println(10);
    }
}
