package COCI;
import java.util.Scanner;

public class COCI_2007_C3_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String message = in.nextLine();
		
		int r = 1;
		int c = 1;
		for (int i = (int) Math.sqrt(message.length()); i > 0; i--) {
			if (message.length() % i == 0) {
				r = i;
				c = message.length() / i;
				break;
			}
		}
		
		char[][] encryption = new char[r][c];
		int count = 0;
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < r; k++) {
				encryption[k][j] = message.charAt(count);
				count++;
			}
		}
		
		for (int k = 0; k < r; k++) {
			for (int j = 0; j < c; j++) {
				System.out.print(encryption[k][j]);
			}
		}
	}

}