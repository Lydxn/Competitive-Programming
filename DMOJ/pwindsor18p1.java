package DMOJ;
import java.util.Scanner;

public class Java {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line = in.nextLine();
		
		int index = line.indexOf("java");
		System.out.println(index == -1 ? line.length() : index);
	}

}
