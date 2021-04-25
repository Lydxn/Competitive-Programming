package ccc_2006;
import java.awt.geom.Line2D;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Point {
	int x;
	int y;
	
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class S3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Point R = new Point(in.nextInt(), in.nextInt());
		Point J = new Point(in.nextInt(), in.nextInt());
		int n = in.nextInt();
		
		@SuppressWarnings("unchecked")
		List<Point>[] buildings = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			int corners = in.nextInt();
			
			buildings[i] = new ArrayList<Point>();
			for (int j = 0; j < corners; j++) {
				buildings[i].add(new Point(in.nextInt(), in.nextInt()));
			}
		}
		
		int blocked = 0;
		for (List<Point> i : buildings) {
			for (int j = 0; j < i.size() - 1; j++) {
				if (Line2D.linesIntersect(R.x, R.y, J.x, J.y, i.get(j).x, i.get(j).y, i.get(j + 1).x, i.get(j + 1).y)) {
					blocked++;
					break;
				}
			}
		}
		System.out.println(blocked);
	}

}
