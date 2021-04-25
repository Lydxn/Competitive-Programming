package DMOJ;
import java.util.Scanner;

public class P2_LOL {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int minX = Integer.MAX_VALUE;
		int maxX = Integer.MIN_VALUE;
		int minY = Integer.MAX_VALUE;
		int maxY = Integer.MIN_VALUE;
		
		for (int i = 0; i < N; i++) {
			int X = in.nextInt();
			int Y = in.nextInt();
			
			minX = Math.min(minX, X);
			maxX = Math.max(maxX, X);
			minY = Math.min(minY, Y);
			maxY = Math.max(maxY, Y);
		}
		System.out.println((maxX - minX) * (maxY - minY));
	}
	
}
