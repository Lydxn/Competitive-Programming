import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();

		for (int i = 0; i < s.length() - 1; i++) {
			for (int j = i + 2; j < s.length() + 1; j += 2) {
				String subS = s.substring(i, j);
				if (palindrome(subS)) {
					System.out.println("Even");
					return;
				}
			}
		}
		System.out.println("Odd");
	}

	private static boolean palindrome(String s) {
		int a = 0;
		int b = s.length() - 1;

		while (a < b && s.charAt(a) == s.charAt(b)) {
			a++;
			b--;
		}
		return a < b ? false : true;
	}
}
