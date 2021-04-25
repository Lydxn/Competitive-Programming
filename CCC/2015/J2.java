package ccc_2015;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String emote = in.nextLine();
		
		int happy = 0;
		int sad = 0;
		
		for (int i = 0; i < emote.length() - 2; i++) {
			if (emote.charAt(i) == ':' && emote.charAt(i + 1) == '-' && emote.charAt(i + 2) == ')') {
				happy++;
			}
			
			if (emote.charAt(i) == ':' && emote.charAt(i + 1) == '-' && emote.charAt(i + 2) == '(') {
				sad++;
			}
		}
		
		if (happy > sad) {
			System.out.println("happy");
		} else if (happy < sad) {
			System.out.println("sad");
		} else if (happy == 0 && sad == 0) {
			System.out.println("none");
		} else {
			System.out.println("unsure");
		}
	}

}
