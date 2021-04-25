package ccc_2012;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int J = in.nextInt();
		
		System.out.println((J - 1) * (J - 2) * (J - 3) / 6);
	}

}
