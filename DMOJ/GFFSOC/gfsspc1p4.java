package DMOJ;
import java.util.Scanner;

public class Bruno_And_Fibonacci {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		boolean[] fib = fib(500);
		String DNA = in.nextLine();
		
		for (int i = 0; i < N; i++) {
			boolean isFib = fib[i + 1];
			boolean isA = DNA.charAt(i) == 'A';

			if (isFib ^ isA) {
				System.out.println("Bruno, GO TO SLEEP");
				return;
			}
		}
		System.out.println("That's quite the observation!");
	}
	
	private static boolean[] fib(int lim) {
		boolean[] fib = new boolean[lim + 1];
		int a = 0;
		int b = 1;
		int c;
		
		while (true) {
			c = a + b;
			a = b;
			b = c;
			
			if (b > 500) {
				break;
			}
			fib[b] = true;
		}
		return fib;
	}

}