package ccc_1998;
import java.util.Scanner;

public class P1 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < n; i++) {
			String line = in.nextLine();
			String[] words = line.split("\\W+");

			for (int j = 0; j < words.length; j++) {
				if (words[j].length() == 4) {
					words[j] = "****";
				}
			}
			System.out.println(String.join(",", words).replaceAll(",", " "));
		}
	}
	
}
