package COCI;
import java.util.Scanner;

public class COCI_2006_C5_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char[] moves = in.nextLine().toCharArray();
		boolean[] ball = {true, false, false};
		
		for (char i : moves) {
			if (i == 'A') {
				swap(ball, 0, 1);
			} else if (i == 'B') {
				swap(ball, 1, 2);
			} else {
				swap(ball, 0, 2);
			}
		}
		
		System.out.println(ball[0] ? 1 : (ball[1] ? 2 : 3));
	}
	
	private static void swap(boolean[] ball, int a, int b) {
		boolean temp = ball[a];
		ball[a] = ball[b];
		ball[b] = temp;
	}

}
