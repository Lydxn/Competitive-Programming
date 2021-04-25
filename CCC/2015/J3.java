package ccc_2015;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		String word = in.nextLine();
		
		String consonants = "bcdfghjklmnpqrstvwxyz";
		String closestVowel = "aaeeeiiiiooooouuuuuuu";
		String nextConsonant = "cdfghjklmnpqrstvwxyzz";
		
		String rovarspraket = "";
		for (int i = 0; i < word.length(); i++) {
			String conCheck = word.substring(i, i + 1);
			int place = consonants.indexOf(conCheck);
			
			rovarspraket += word.substring(i, i + 1);
			if (consonants.contains(conCheck)) {
				rovarspraket += closestVowel.substring(place, place + 1) + nextConsonant.substring(place, place + 1);
			}
		}
		System.out.println(rovarspraket);
	}

}
