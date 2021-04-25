package COCI;
import java.util.ArrayList;
import java.util.Scanner;

public class COCI_2006_C3_P3 {
	
	static class Point {
		int x, y;
		Point (int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		ArrayList<Point> alpha = new ArrayList<Point>();
		for (int i = 0; i < N; i++) {
			String row = in.next();
			for (int j = 0; j < N; j++) {
				if (row.charAt(j) != '.') {
					alpha.add(new Point(i, j));
				}
			}
		}
		
		int count = 0;
		for (int k = 0; k < alpha.size(); k++) {
			for (int l = k + 1; l < alpha.size(); l++) {
				for (int m = l + 1; m < alpha.size(); m++) {
					if (triplet(alpha.get(k), alpha.get(l), alpha.get(m))) {
						count++;
					}
				}
			}
		}
		System.out.println(count);
	}
	
	private static boolean triplet(Point p1, Point p2, Point p3) {
		double x1 = p1.x;
		double x2 = p2.x;
		double x3 = p3.x;
		double y1 = p1.y;
		double y2 = p2.y;
		double y3 = p3.y;
		return (y2 - y1) / (x2 - x1) == (y3 - y2) / (x3 - x2);
	}

}