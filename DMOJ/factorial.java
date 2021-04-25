package DMOJ;
import java.util.Scanner;

public class Fast_Factorial_Calculator {
	
	static final long MOD = 1L << 32;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String n = in.nextLine();
			
			if (n.length() > 2) {
				System.out.println(0);
			} else {
				long res = 1;
				for (int j = 2; j <= Integer.parseInt(n); j++) {
					res = (res * j) % MOD;
				}
				System.out.println(res);
			}
		}
	}

}