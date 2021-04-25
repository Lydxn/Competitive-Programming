package ccc_2005;
import java.util.Scanner;

public class J5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			String word = in.nextLine();
			if (word.equals("X")) {
				return;
			}
			
			while (word.indexOf("ANA") != -1 || word.indexOf("BAS") != -1) {
				word = word.replaceAll("ANA", "A").replaceAll("BAS", "A");
			}
			System.out.println(word.equals("A") ? "YES" : "NO");
		}
	}

}
