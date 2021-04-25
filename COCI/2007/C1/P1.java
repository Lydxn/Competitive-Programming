package COCI;
import java.util.Scanner;

public class COCI_2007_C1_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x = in.nextInt();
		int y = in.nextInt();
		
		x ^= in.nextInt();
		y ^= in.nextInt();
		x ^= in.nextInt();
		y ^= in.nextInt();
		System.out.println(x + " " + y);
	}

}