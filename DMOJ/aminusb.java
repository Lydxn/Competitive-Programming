package DMOJ;
import java.util.Scanner;

public class A_Minus_B {

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		short N = in.nextShort();
		
		for (int i = 0; i < N; i++) {
		    int A = in.nextInt();
		    int B = in.nextInt();
		    System.out.println(A - B);
		}
    }

}
