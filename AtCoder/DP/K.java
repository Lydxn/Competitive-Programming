package AtCoder.DP;
import java.util.Arrays;
import java.util.Scanner;

public class Stones {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		
		int[] moves = new int[N];
		for (int i = 0; i < moves.length; i++) {
			moves[i] = in.nextInt();
		}
		
		boolean[] outcomes = new boolean[K + 1];
		Arrays.fill(outcomes, true);
		
		for (int i = 1; i < outcomes.length; i++) {
			for (int m : moves) {
				if (m <= i && outcomes[i - m]) {
					outcomes[i] = false;
				}
			}
		}
		System.out.println(outcomes[K] ? "Second" : "First");
	}

}