package ccc_2001;
import java.util.Scanner;

public class S1_J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter cards:");
		String cards = in.nextLine();
		System.out.println("");
		System.out.printf("%-35s %-25s \n", "Cards Dealt", "Points");

		int clubI = 0, diamI = 0, hearI = 0, spadI = 0;
		for (int i = 0; i < cards.length(); i++) {
			if (cards.charAt(i) == 'C') {
				clubI = i;
			} else if (cards.charAt(i) == 'D') {
				diamI = i;
			} else if (cards.charAt(i) == 'H') {
				hearI = i;
			} else if (cards.charAt(i) == 'S') {
				spadI = i;
			}
		}
		
		String cd = cards.substring(clubI + 1, diamI).replaceAll("", " ");
		String dh = cards.substring(diamI + 1, hearI).replaceAll("", " ");
		String hs = cards.substring(hearI + 1, spadI).replaceAll("", " ");
		String s_ = cards.substring(spadI + 1, cards.length()).replaceAll("", " "); 
		
		System.out.printf("%-35s %4d \n", "Clubs" + cd, points(cd));
		System.out.printf("%-35s %4d \n", "Diamonds" + dh, points(dh));
		System.out.printf("%-35s %4d \n", "Hearts" + hs, points(hs));
		System.out.printf("%-35s %4d \n", "Spades" + s_, points(s_));
		System.out.printf("%37s %2d", "Total", (points(cd) + points(dh) + points(hs) + points(s_)));
	}
	
	private static int points(String hand) {
		int p = 0;
		int count = 0;
		
		for (int i = 0; i < hand.length(); i++) {
			if (hand.charAt(i) == 'J') {
				p += 1;
			} else if (hand.charAt(i) == 'Q') {
				p += 2;
			} else if (hand.charAt(i) == 'K') {
				p += 3;
			} else if (hand.charAt(i) == 'A') {
				p += 4;
			} 
			if (Character.isLetter(hand.charAt(i)) || Character.isDigit(hand.charAt(i))) {
				count++;
			}
		}
		if (count == 2) {
			p += 1;
		} else if (count == 1) {
			p += 2;
		} else if (count == 0) {
			p += 3;
		}
		return p;
	}

}
