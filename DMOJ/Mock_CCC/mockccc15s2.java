package DMOJ;
import java.util.Scanner;

public class Problem_Setting_Pandemonium_Senior {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] difficulty = new int[100000];
		for (int i = 0; i < N; i++) {
			difficulty[in.nextInt()]++;
		}
		
		int mode = 0;
		for (int d : difficulty) {
			mode = Math.max(mode, d);
		}
		System.out.println(mode);
	}

}
