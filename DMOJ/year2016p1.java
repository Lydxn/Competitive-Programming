package DMOJ;
import java.util.Scanner;

public class Late_Christmas_Shopping {

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[] duplicates = new int[11];
		for (int i = 0; i < N; i++) {
			int M = in.nextInt();
			
			boolean[] check = new boolean[11];
			for (int j = 0; j < M; j++) {
				check[in.nextInt()] = true;
			}
			
			for (int j = 0; j < check.length; j++) {
				if (check[j]) {
					duplicates[j]++;
				}
			}
		}
		
		for (int d : duplicates) {
			if (d > 1) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}

}