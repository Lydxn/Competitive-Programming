package DMOJ.Valentines_Day;
import java.util.Scanner;

public class Valentines_Day_2019_J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int pink = 0;
		for (int i = 0; i < N; i++) {
			int R = in.nextInt();
			int G = in.nextInt();
			int B = in.nextInt();
			
			if (240 <= R && R <= 255 && 0 <= G && G <= 200 && 95 <= B && B <= 220) {
				pink++;
			}
		}
		System.out.println(pink);
	}

}
