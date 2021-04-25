package ccc_2013;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int Y = in.nextInt();
		int M = in.nextInt();
		
		int diff = Math.abs(M - Y);
		System.out.println(M + diff);
	}

}
