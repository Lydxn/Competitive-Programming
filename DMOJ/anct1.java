package DMOJ;
import java.util.Scanner;

public class Troubling_Times {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int D = in.nextInt();
		
		int minJumps = Integer.MAX_VALUE;
		for (int i = 0; i < N; i++) {
			int interval = in.nextInt();
			if (D % interval == 0) {
				minJumps = Math.min(minJumps, Math.abs(D / interval));
			}
		}
		System.out.println(minJumps == Integer.MAX_VALUE ? "This is not the best time for a trip." : minJumps);
	}

}
