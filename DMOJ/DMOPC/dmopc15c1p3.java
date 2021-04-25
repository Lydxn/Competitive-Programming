import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String S = in.nextLine();
		String T = in.nextLine();

		for (int i = 0; i < 26; i++) {
			if (S.contains(T)) {
				System.out.println(i + "\n" + S);
				return;
			}
			S = shift(S);
		}
	}

	private static String shift(String S) {
		String res = "";
		for (int i = 0; i < S.length(); i++) {
			res += (char) (Math.floorMod(S.charAt(i) - 'a' - 1, 26) + 'a');
		}
		return res;
	}

}
