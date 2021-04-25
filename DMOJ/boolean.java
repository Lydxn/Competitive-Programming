package DMOJ;
import java.util.Scanner;

public class Boolean {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String bool = in.nextLine();
		
		String[] nots = bool.split("not");
		System.out.println(((nots.length & 1) == 1 && bool.contains("True")) ||
							(nots.length & 1) == 0 && bool.contains("False") ? "True" : "False");
	}

}
