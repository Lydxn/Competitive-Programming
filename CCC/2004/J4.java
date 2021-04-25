package ccc_2004;
import java.util.Scanner;

public class J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String keyword = in.nextLine();
		String code = in.nextLine();
		code = code.replaceAll("\\W", "");
		
		String result = "";
		for (int i = 0; i < code.length(); i++) {
			result += new String(Character.toChars((ascii(code, i) + ascii(keyword, i % keyword.length())) % 26 + 65));
		}
		System.out.println(result);
	}
	
	private static int ascii(String word, int pos) {
		return Character.codePointAt(word, pos) - 65;
	}

}
