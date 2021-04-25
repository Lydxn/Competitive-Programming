package DMOJ;
import java.util.Scanner;

public class Creating_A_Sequence {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		
		System.out.print(K);
		for (int i = 0; i < N - 1; i++) {
			System.out.print(" 0");
		}
	}

}
