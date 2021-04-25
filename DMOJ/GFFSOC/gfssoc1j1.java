package DMOJ;
import java.util.Scanner;

public class Flying_Plushies {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		
		int plushies = 0;
		for (int i = 0; i < M; i++) {
			if (in.nextInt() >= N) {
				plushies++;
			}
		}
		System.out.println(plushies);
	}

}