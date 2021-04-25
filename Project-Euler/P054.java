package euler100;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class P054 {

	public static void main(String[] args) throws IOException {
		String[][][] cards = new String[1000][2][5];

		BufferedReader br = new BufferedReader(new FileReader("src/txt/p054_poker.txt"));
		for (int i = 0; i < 1000; i++) {
			String hands = br.readLine();
			cards[i][0] = hands.substring(0, 14).split(" ");
			cards[i][1] = hands.substring(15).split(" ");
		}
		br.close();

		int wins = 0;
		for (String[][] i : cards) {
			int[][] player1 = handArr(i[0]);
			int[][] player2 = handArr(i[1]);
			Arrays.sort(player1[0]);
			Arrays.sort(player2[0]);
			
			if (win1(player1, player2)) {
				wins++;
			}
		}
		System.out.println(wins);
	}	
	
	private static boolean win1(int[][] player1, int[][] player2) {
		if (straightFlush(player1) != straightFlush(player2)) {return straightFlush(player1) > straightFlush(player2);}
		if (quads(player1)   	   != quads(player2))   	  {return quads(player1)   		 > quads(player2);}
		if (fullHouse(player1)     != fullHouse(player2))     {return fullHouse(player1)     > fullHouse(player2);}
		if (flush(player1)         != flush(player2))         {return flush(player1)         > flush(player2);}
		if (straight(player1)      != straight(player2))      {return straight(player1)      > straight(player2);}
		if (trips(player1)  	   != trips(player2))  		  {return trips(player1)    	 > trips(player2);}
		if (twoPair(player1)       != twoPair(player2))       {return twoPair(player1)       > twoPair(player2);}
		if (pair(player1)          != pair(player2))          {return pair(player1)          > pair(player2);}
		return high(player1, player2);
	}
	
	private static int[][] handArr(String[] cards) {
		int[][] hand = new int[2][cards.length];
		for (int i = 0; i < cards.length; i++) {
			hand[0][i] = "23456789TJQKA".indexOf(cards[i].charAt(0)) + 2;
			hand[1][i] = "DCHS".indexOf(cards[i].charAt(1));
		}
		return hand;
	}
	
	private static boolean high(int[][] hand1, int[][] hand2) {
		for (int i = hand1[0].length - 1; i >= 0; i--) {
			if (hand1[0][i] > hand2[0][i]) { 
				return true;
			} else if (hand1[0][i] < hand2[0][i]){
				return false;
			}
		}
		return false;
	}

	private static int pair(int[][] hand) {
		for (int i = 0; i < hand[0].length - 1; i++) {
			if (hand[0][i] == hand[0][i + 1]) {
				return hand[0][i];
			}
		}
		return 0;
	}
	
	private static int twoPair(int[][] hand) {
        for (int i = 0; i < hand[0].length - 3; i++) {
        	for (int j = i + 2; j < hand[0].length - 1; j++) {
	        	if (hand[0][i] == hand[0][i + 1] && hand[0][j] == hand[0][j + 1]) {
	        		return Math.max(hand[0][i], hand[0][j]);
	        	}
        	}
        }
        return 0;
    }
	
	private static int trips(int[][] hand) {
		for (int i = 0; i < hand[0].length - 2; i++) {
			if (hand[0][i] == hand[0][i + 2]) {
				return hand[0][i];
			}
		}
		return 0;
	}

	private static int straight(int[][] hand) {
		for(int i = 0; i < hand[0].length - 1; i++) {
			if(hand[0][i] + 1 != hand[0][i + 1]) {
				return 0;
			}
		}
		return hand[0][4];
	}
	
	private static int flush(int[][] hand) {
		for (int i = 0; i < hand[1].length - 1; i++) {
			if (hand[1][i] != hand[1][i + 1]) {
				return 0;
			}
		}
		return hand[0][4];
	}

	private static int fullHouse(int[][] hand) {
		for (int i = 1; i < 3; i++) {
			if (hand[0][0] == hand[0][i] && hand[0][i + 1] == hand[0][4]) {
				return hand[0][2];
			}
		}
		return 0;
	}

	private static int quads(int[][] hand) {
		for (int i = 0; i < 2; i++) {
			if (hand[0][i] == hand[0][i + 3]) {
				return hand[0][i];
			}
		}
		return 0;
	}	
	
	private static int straightFlush(int[][] hand) {
		return straight(hand) + flush(hand) != 0 ? hand[0][4] : -1;
	}
	
}
