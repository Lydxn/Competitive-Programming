package ccc_2011;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		int tCount = 0;
		int sCount = 0;
		for (int i = 0; i < N; i++) {
			String sentence = in.nextLine();
			for (int j = 0; j < sentence.length(); j++) {
				if (sentence.charAt(j) == 't' || sentence.charAt(j) == 'T') {
					tCount++;
				} else if (sentence.charAt(j) == 's' || sentence.charAt(j) == 'S') {
					sCount++;
				}
			}
		}
		System.out.println(tCount > sCount ? "English" : "French");
	}

}
