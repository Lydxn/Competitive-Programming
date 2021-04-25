package DMOJ;
import java.util.Scanner;

public class Vasile_And_Haircuts {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		for (int i = 0; i < N; i++) {
			int L = in.nextInt();
			int A = in.nextInt();
			int B = in.nextInt();
			int F = in.nextInt();
			
			System.out.println(A <= L - F && L - F <= B ? "Yes" : "No");
		}
	}	

}