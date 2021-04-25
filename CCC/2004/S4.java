package ccc_2004;
import java.util.Scanner;

public class S4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sx = in.nextInt();
		int sy = in.nextInt();
		int sz = in.nextInt();
		int tx = in.nextInt();
		int ty = in.nextInt();
		int tz = in.nextInt();
		
		int ox = tx - sx;
		int oy = ty - sy;
		int oz = tz - sz;
		
		int minDist = Integer.MAX_VALUE;
		outer: while (true) {
			int d = in.nextInt();
			char c = in.next().charAt(0);
			
			int nx = ox - d;
			minDist = Math.min(minDist, (nx * ox < 0 ? 0 : nx * nx) + oy * oy + oz * oz);
			ox -= d;
			
			int temp = ox;
			switch (c) {
			case 'L':
				ox = oy;
				oy = -temp;
				break;
			case 'R':
				ox = -oy;
				oy = temp;
				break;
			case 'U':
				ox = oz;
				oz = -temp;
				break;
			case 'D':
				ox = -oz;
				oz = temp;
				break;
			default:
				break outer;
			}
		} 
		System.out.printf("%.2f\n", Math.sqrt(minDist));
	}

}
