package DMOJ;
import java.util.Scanner;

public class Composite_Bag {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int take = 0;
		for (int i = 0; i < N; i++) {
			if (isComposite(in.nextInt())) {
				take++;
			}
		}
		System.out.println(take);
	}

	private static boolean isComposite(int n) {
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return true;
			}
		}
		return false;
	}
	
}