package DMOJ;
import java.util.Scanner;

public class Ren_Ashbell {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		boolean strongest = true;
		int power = in.nextInt();
		
		for (int i = 1; i < N; i++) {
			if (in.nextInt() >= power) {
				strongest = false;
			}
		}
		System.out.println(strongest ? "YES" : "NO");
	}

}
