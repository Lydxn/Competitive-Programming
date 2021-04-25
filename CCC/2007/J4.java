package ccc_2007;
import java.util.Arrays;
import java.util.Scanner;

public class J4 {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		System.out.print("Enter first phrase> ");
		String phrase1 = in.nextLine();
		System.out.print("Enter second phrase> ");
		String phrase2 = in.nextLine();
		
		phrase1 = sortString(phrase1.replaceAll(" ", ""));
		phrase2 = sortString(phrase2.replaceAll(" ", ""));

		System.out.println((phrase1.equals(phrase2) ? "Is " : "Is not ") + "an anagram.");
	}
	
	public static String sortString(String phrase) {
		char[] temp = phrase.toCharArray();
		Arrays.sort(temp);
		return new String(temp);
	}

}
