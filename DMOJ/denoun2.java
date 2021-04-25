package DMOJ;
import java.io.*;
import java.util.Scanner;

public class More_German_Nouns {

	public static void main(String[] args) throws UnsupportedEncodingException {
		Scanner in = new Scanner(new InputStreamReader(System.in, "UTF-8"));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out, "UTF-8"));
		
		int n = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < n; i++) {
			String line = in.nextLine();
			String[] words = line.split(" ");
			
			for (int w = 0; w < words.length; w++) {
				if (Character.isUpperCase(words[w].codePointAt(0))) {
					out.println(words[w].replaceAll("[\\s?!'():;]", ""));
				}
			}
		}
		out.close();
	}

}