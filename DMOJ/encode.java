package DMOJ;
import java.util.Scanner;

public class Encode {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		String S = in.nextLine();

		String res = "";
		for (int i = 0; i < S.length(); i++) {
			char ch = S.charAt(i);
			res += ch == ' ' ? ' ' : (Character.isLowerCase(ch) ? (char) (Math.floorMod(ch - 'a' - N, 26) + 'a') : 
																  (char) (Math.floorMod(ch - 'A' - N, 26) + 'A') );
		}
		System.out.println(res);
	}

}
