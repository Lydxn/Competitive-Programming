package COCI;
import java.util.Scanner;

public class COCI_2006_C4_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int A = in.nextInt();
		
		for (int i = 1; i < N; i++) {
			int B = in.nextInt();
			System.out.println((A / gcf(A, B)) + "/" + (B / gcf(A, B)));
		}
	}
	
	private static int gcf(int a, int b) {
		return b == 0 ? a : gcf(b, a % b);
	}

}
