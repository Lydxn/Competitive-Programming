package DMOJ;
import java.util.Scanner;

public class Festive_Fardin {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String shirt = in.nextLine();
		String pants = in.nextLine();

		System.out.println((shirt.equals("red") || shirt.equals("green") || shirt.equals("white")) &&
						   (pants.equals("red") || pants.equals("green") || pants.equals("white"))
						   ? "Jingle Bells" : "Boring...");
	}

}