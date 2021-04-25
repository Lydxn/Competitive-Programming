package ccc_1997;
import java.util.Scanner;

public class P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		for (int i = 0; i < n; i++) {
			int undef = in.nextInt();
			int onels = 0;
			int elimn = 0;
			int rounds = 0;
			
			while (undef != 1 || onels != 1) {
				System.out.printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", rounds, undef, onels, elimn);
				elimn += onels / 2;
				onels = (int) Math.ceil(onels / 2.0);
				onels += undef / 2;
				undef = (int) Math.ceil(undef / 2.0);
				rounds++;
			}
			
			System.out.printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", rounds, undef, onels, elimn);
		    System.out.printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", ++rounds, --undef, ++onels, elimn);
		    System.out.printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", ++rounds, undef, --onels, ++elimn);
			System.out.println("There are " + rounds + " rounds.");
		}
	}

}
