import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();

		for (int i = 1; i < str.length(); i++) {
			if (palindrome(str.substring(0, i)) && palindrome(str.substring(i))) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}

	public static boolean palindrome(String str) {
		return str.equals(new StringBuilder(str).reverse().toString());
	}
}
