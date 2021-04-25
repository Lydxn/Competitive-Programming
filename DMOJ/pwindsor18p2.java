package DMOJ;
import java.util.Scanner;

class LawnPoint {
	int x;
	int y;
	
	public LawnPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public double dist() {
		return Math.sqrt(Math.pow(this.x, 2) + Math.pow(this.y, 2));
	}
}

public class Get_Off_My_Lawn {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		LawnPoint maxPoint = new LawnPoint(0, 0);
		double maxDist = Double.MIN_VALUE;
		
		for (int i = 0; i < N; i++) {
			LawnPoint point = new LawnPoint(in.nextInt(), in.nextInt());
			
			double dist = point.dist();
			if (maxDist < dist) {
				maxDist = dist;
				maxPoint = new LawnPoint(point.x, point.y); 
			}
		}
		System.out.println(maxPoint.x + " " + maxPoint.y);
	}

}