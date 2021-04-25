package DMOJ;
import java.util.Scanner;

public class Food_Selection {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int C = in.nextInt();
		int F = in.nextInt();
		int S = in.nextInt();
		
		int N = in.nextInt();
		for (int i = 0; i < N; i++) {
			int Xi = in.nextInt();
			int Ci = in.nextInt();
			int Fi = in.nextInt();
			int Si = in.nextInt();
			String food = in.nextLine();
			
			if ((double) Ci / Xi <= C && (double) Fi / Xi <= F && (double) Si / Xi <= S) {
				System.out.println(food);
			}
		}
	}

}