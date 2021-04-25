package ccc_1999;
import java.util.Scanner;

public class P1 {
	
	static Scanner in = new Scanner(System.in);
	static String[] card = new String[52];
	
	public static void main(String[] args) {
		int A = 0;
		int B = 0;
		int AorB;
		for (int i = 0; i < 52; i++) {
			card[i] = in.nextLine();
		}
		
		for (int j = 0; j < 52; j++) {
			if (card[j].equals("jack") && notHigh(j, 1)) {
				AorB = 1;
			} else if (card[j].equals("queen") && notHigh(j, 2)) {
				AorB = 2;
			} else if (card[j].equals("king") && notHigh(j, 3)) {
				AorB = 3;
			} else if (card[j].equals("ace") && notHigh(j, 4)) {
				AorB = 4;
			} else {
				AorB = 0;
			}
			
			String scorer = "";
			if (AorB != 0) {
				if (j % 2 == 0) {
					scorer = "A";
					A += AorB;
				} else {
					scorer = "B";
					B += AorB;
				}
				System.out.println("Player " + scorer + " scores " + AorB + " point(s).");
			}
		}
		
		System.out.println("Player A: " + A + " point(s).");
		System.out.println("Player B: " + B + " point(s).");
	}

	private static boolean notHigh(int start, int next) {
		if (start + next >= 52) {
			return false;
		}
		
		for (int i = start + 1; i <= start + next; i++) {
			if (card[i].equals("jack") || card[i].equals("queen") || card[i].equals("king") || card[i].equals("ace")) {
				return false;
			}
		}
		return true;
	}
}
