package DMOJ;
import java.util.Scanner;

public class Snowball_Fight {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int h1 = in.nextInt();
		int w1 = in.nextInt();
		int h2 = in.nextInt();
		int w2 = in.nextInt();
		
		int hits1 = w1 * (h2 - 1);
		int hits2 = w2 * (h1 - 1);
		System.out.println(hits1 > hits2 ? 2 : (hits1 < hits2 ? 1 : -1));
	}

}