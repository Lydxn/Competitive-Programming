package COCI;
import java.util.Scanner;

public class COCI_2006_C2_P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		System.out.println(N * (N - 1) * (N - 2) * (N - 3) / 24);
	}

}
