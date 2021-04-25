import java.util.Scanner;

public class S1_J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String flips = in.nextLine();

		int H = 0;
		int S = 0;
		for (int i = 0; i < flips.length(); i++) {
			if (flips.charAt(i) == 'H') {
				H++;
			} else {
				S++;
			}
		}

		System.out.println(H % 2 == 0 ? (S % 2 == 0 ? printFlips(1, 2, 3, 4) : printFlips(2, 1, 4, 3)) :
					 	  (S % 2 == 0 ? printFlips(3, 4, 1, 2) : printFlips(4, 3, 2, 1)));
	}
	
	private static String printFlips(int a, int b, int c, int d) {
		return a + " " + b + "\n" + c + " " + d;
	}

}
