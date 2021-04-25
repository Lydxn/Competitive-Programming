package ccc_2004;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Number of tiles?");
		int tiles = in.nextInt();
		
		System.out.println("The largest square has side length " + (int) Math.floor(Math.sqrt(tiles)) + ".");
	}

}
