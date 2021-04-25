package DMOJ;
import java.util.Scanner;

public class Homework {
	
	static int[] primacities = primacities(10000001);

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		for (int i = 1; i <= T; i++) {
			int A = in.nextInt();
			int B = in.nextInt();
			int K = in.nextInt();
			
			System.out.println("Case #" + i + ": " + primacity(A, B, K));
		}
	}
	
	private static int primacity(int A, int B, int K) {
		int count = 0;
		for (int i = A; i <= B; i++) {
			if (primacities[i] == K) {
				count++;
			}
		}
		return count;
	}
	
	private static int[] primacities(int lim) {
		int[] primacities = new int[lim];
		for (int i = 2; i < lim; i++) {
			if (primacities[i] == 0) {
				for (int j = i; j < lim; j += i) {
					primacities[j]++;
				}
			}
		}
		return primacities;
	}

}