package COCI;
import java.util.Scanner;

public class COCI_2006_C4_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int W = in.nextInt();
		int H = in.nextInt();
		
		for (int i = 0; i < N; i++) {
			int length = in.nextInt();
			if (length > Math.sqrt(W * W + H * H)) {
				System.out.println("NE");
			} else {
				System.out.println("DA");
			}
		}
	}

}
