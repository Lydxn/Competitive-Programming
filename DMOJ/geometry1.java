package DMOJ;
import java.util.Scanner;

class Point {
	int x;
	int y;
	
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Troubling_Triangles {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		for (int i = 0; i < N; i++) {
			Point X = new Point(in.nextInt(), in.nextInt());
			Point Y = new Point(in.nextInt(), in.nextInt());
			Point Z = new Point(in.nextInt(), in.nextInt());
			
			double A = dist(X.x, Y.x, X.y, Y.y);
			double B = dist(Y.x, Z.x, Y.y, Z.y);
			double C = dist(X.x, Z.x, X.y, Z.y);
			System.out.println(area(A, B, C) + " " + perimeter(A, B, C));
		}
	}
	
	private static double area(double A, double B, double C) {
		double S = (A + B + C) / 2;
		return Math.sqrt(S * (S - A) * (S - B) * (S - C));
	}
	
	private static double perimeter(double A, double B, double C) {
		return A + B + C;
	}
	
	private static double dist(double x1, double x2, double y1, double y2) {
		return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
	}
}
