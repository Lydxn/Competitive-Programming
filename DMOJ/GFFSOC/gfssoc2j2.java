package DMOJ;
import java.util.Scanner;

public class Fizz_Fuzz {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		for (int i = 1, j = 1; i <= N; i++, j += 2) {
			fizzBuzz(i);
			System.out.print(" ");
			
			fizzBuzz(j);
			System.out.println();
		}
	}
	
	private static void fizzBuzz(int N) {
		boolean mod7 = N % 7 == 0;
		boolean mod13 = N % 13 == 0;
		
		if (mod7 && mod13) {
			System.out.print("Fizz Fuzz");
		} else if (mod7) {
			System.out.print("Fizz");
		} else if (mod13) {
			System.out.print("Fuzz");
		} else {
			System.out.print(N);
		}
	}

}
