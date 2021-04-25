import java.util.Arrays;
import java.util.Scanner;

public class P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			char[] str = in.nextLine().toCharArray();
			Arrays.sort(str);
			printAnagram(String.valueOf(str), "");
		}
	}

	private static void printAnagram(String str, String res) {
		if (str.isEmpty()) {
			System.out.println(res);
		} else {
			for (int i = 0; i < str.length(); i++) {
				printAnagram(str.substring(0, i) + str.substring(i + 1), res + str.charAt(i));
			}
		}
	}

}
