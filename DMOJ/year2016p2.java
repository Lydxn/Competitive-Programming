package DMOJ;
import java.util.Scanner;

public class The_365_Days_Of_Christmas {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		String[] verses = new String[N];
		for (int i = 0; i < verses.length; i++) {
			verses[i] = in.nextLine();
		}
		
		for (int i = 0; i < verses.length; i++) {
			System.out.println("On the " + (i + 1) + ordinal(i + 1) + " day of Christmas my true love sent to me:");
			for (int j = i; j >= 0; j--) {
				System.out.println((j == 0 && i != 0 ? "and " : "") + (j + 1) + " " + verses[j]);
			}
			System.out.println();
		}
	}
	
	private static String ordinal(int n) {
		if (n % 100 >= 11 && n % 100 <= 13) {
			return "th";
		} else if (n % 10 == 1) {
			return "st";
		} else if (n % 10 == 2) {
			return "nd";
		} else if (n % 10 == 3) {
			return "rd";
		} else {
			return "th";
		}
	}
	
}