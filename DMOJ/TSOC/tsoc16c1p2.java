package DMOJ;
import java.util.Scanner;

public class Johnny_And_Garden {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String file = in.nextLine();
		String extension = "";
		
		if (file.contains(".")) {
			String[] full = file.split("\\.");
			file = full[0];
			extension = full[1].toLowerCase();
		} else {
			extension = in.nextLine().toLowerCase();
		}
		System.out.println("\"" + file + "\"" + " - " + extension);
	}

}
