import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int chunks = 0;

		String straw = "";
		for (int i = 0; i < 7; i++) {
			straw += in.nextLine();
		}
		straw = straw.replace("JJ", "J");
		straw = straw.replace("JJ", "J");
		straw = straw.replace("JJ", "J");

		for (int i = 0; i < straw.length(); i++) {
			if (straw.charAt(i) == 'J') {
				chunks++;
			}
		}
		System.out.println(chunks);
	}

}
