package COCI;
import java.util.Scanner;

public class COCI_2006_C4_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int R = in.nextInt();
		int C = in.nextInt();
		int ZR = in.nextInt();
		int ZC = in.nextInt();

		for (int i = 0; i < R; i++) {
			char[] maga = in.next().toCharArray();
			for (int j = 0; j < ZR; j++) {
				for (int k = 0; k < C * ZC; k++) {
					System.out.print(maga[k / ZC]);
				}
				System.out.println();
			}
		}
	}

}
