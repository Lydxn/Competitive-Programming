package ccc_2001;
import java.util.Scanner;

public class S4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[][] points = new int[N][2]; 
		for (int i = 0; i < N; i++) {
			points[i][0] = in.nextInt();
			points[i][1] = in.nextInt();
		}
		
		double temp = 1;
		double res = 0;
		
		for (int x = 0; x < N - 2; x++) {
			for (int y = x + 1; y < N - 1; y++) { 
				for (int z = y + 1; z < N; z++) {
					double a = dist(points[x][0], points[x][1], points[y][0], points[y][1]);
					double b = dist(points[y][0], points[y][1], points[z][0], points[z][1]);
					double c = dist(points[z][0], points[z][1], points[x][0], points[x][1]);
					double s = (a + b + c) / 2;
					
					temp = (a * a + b * b - c * c < 0) || (b * b + c * c - a * a < 0) || (c * c + a * a - b * b < 0)? 
						   Math.max(a, Math.max(b, c)) : 
					       (a * b * c) / (2 * Math.sqrt(s * (s - a) * (s - b) * (s - c)));
					res = Math.max(res, temp);
				}
			}
		}
		System.out.printf("%.2f", N == 1 ? 0 : (N == 2 ? dist(points[0][0], points[0][1], points[1][0], points[1][1]) : res));
	}
	
	public static double dist(int x1, int y1, int x2, int y2) {
		return Math.sqrt(Math.pow(y2 - y1, 2) + Math.pow(x2 - x1, 2));
	}

}
