import java.io.*;
import java.util.*;

public class Back_To_School_2006_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String essay = in.nextLine();

		int upper = 0;
		for (int i = 0; i < essay.length(); i++) {
			char ch = essay.charAt(i);
			if (ch != ' ') {
				upper += Character.isUpperCase(ch) ? 1 : -1;
			}
		}
		System.out.println(upper > 0 ? essay.toUpperCase() : (upper < 0 ? essay.toLowerCase() : essay));
	}
}
