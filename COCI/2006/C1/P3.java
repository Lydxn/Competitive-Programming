package COCI;
import java.util.Scanner;

public class COCI_2006_C1_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String word = in.nextLine();
		
		String[] lines = {"", "", ""};
		for (int i = 0; i < word.length(); i++) {
			if ((i + 1) % 3 == 0) {
				lines[0] += "..*..";
				lines[1] += ".*.*.";
				lines[2] += "*." + word.charAt(i) + ".*";
			} else if (i % 3 == 0 && i != 0) {
				lines[0] += ".#.";
				lines[1] += "#.#";
				lines[2] += "." + word.charAt(i) + ".";
			} else {
				lines[0] += "..#.";
				lines[1] += ".#.#";
				lines[2] += "#." + word.charAt(i) + ".";
			}
			
			if (i + 1 == word.length() && word.length() % 3 != 0) {
				lines[0] += ".";
				lines[1] += ".";
				lines[2] += "#";
			}
		}
		
		System.out.println(lines[0]);
		System.out.println(lines[1]);
		System.out.println(lines[2]);
		System.out.println(lines[1]);
		System.out.println(lines[0]);
	}

}
