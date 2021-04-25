package COCI;
import java.util.Scanner;

public class COCI_2007_C5_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int best = N;
		for (int i = 2; i * i <= N; i++) {
			if (N % i == 0) {
				best = i;
				break;
			}
		}
		System.out.println(N - (N / best));
	}

}
