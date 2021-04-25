import java.util.Scanner;

public class DMOPC_2017_C2_P0 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x1 = in.nextInt(), y1 = in.nextInt();
		int x2 = in.nextInt(), y2 = in.nextInt();
		int xs = in.nextInt(), ys = in.nextInt();
		int D = in.nextInt();
		System.out.println(dist(x1, y1, xs, ys) <= D || dist(x2, y2, xs, ys) <= D ? "Yes" : "No");
	}
	
	private static double dist(int x0, int y0, int x1, int y1) {
		return Math.sqrt(Math.pow(x1 - x0, 2) + Math.pow(y1 - y0, 2));
	}

}
