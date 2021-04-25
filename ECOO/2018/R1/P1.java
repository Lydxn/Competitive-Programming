package ECOO;
import java.util.Scanner;

public class ECOO_2018_R1_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int T = in.nextInt();
			int N = in.nextInt();
			in.nextLine();
			
			int delay = 0;
			for (int j = 0; j < N; j++) {
				char ch = in.nextLine().charAt(0);
				if (ch == 'B') {
					delay += T;
				}
				
				if (delay > 0) {
					delay--;
				}
			}
			System.out.println(delay);
		}
	}

}
