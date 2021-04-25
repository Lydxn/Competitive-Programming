package DMOJ;
import java.util.Scanner;

public class Inaho_IV {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		double[] curr = new double[N];
		for (int i = 0; i < curr.length; i++) {
			curr[i] = in.nextDouble();
		}
		
		double[] dest = new double[N];
		for (int i = 0; i < dest.length; i++) {
			dest[i] = in.nextDouble();
		}
		
		double dist = 0;
		for (int i = 0; i < N; i++) {
			dist += Math.pow(dest[i] - curr[i], 2);
		}
		System.out.println(Math.sqrt(dist));
	}

}