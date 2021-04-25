package DMOJ;
import java.util.Scanner;

public class CodeFights {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int A = in.nextInt();
		int N = in.nextInt();
		
		for (int i = 0; i < N; i++) {
			int k = in.nextInt();
			System.out.println(Math.abs(A - k) > 100 ? "go away! 3:<" : "fite me! >:3");
		}
	}

}