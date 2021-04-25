package ccc_2014;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		in.nextInt();
		in.nextLine();	
		String whoVotes = in.nextLine();
		
		int aVote = 0;
		int bVote = 0;
		
		for (int i = 0; i < whoVotes.length(); i++) {
			if (whoVotes.charAt(i) == 'A') { 
				aVote++;
			} else {
				bVote++;
			}
		}
		
		if (aVote > bVote) {
			System.out.println('A');
		} else if (aVote < bVote) {
			System.out.println('B');
		} else {
			System.out.println("Tie");
		}
	}

}
