package DMOJ;
import java.util.*;

class Card {
	String name;
	int cost;
	
	public Card(String name, int cost) {
		this.name = name;
		this.cost = cost;
	}
}

public class Hearth {

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int T = in.nextInt();
		
		Card[] cards = new Card[N];
		for (int i = 0; i < cards.length; i++) {
			cards[i] = new Card(in.next(), in.nextInt());
		}
		
		Arrays.sort(cards, new Comparator<Card>() {
			public int compare(Card o1, Card o2) {
				return o1.name.compareTo(o2.name);
			}
		});

		for (int i = 0; i < cards.length - 2; i++) {
			for (int j = i + 1; j < cards.length - 1; j++) {
				for (int k = j + 1; k < cards.length; k++) {
					if (cards[i].cost + cards[j].cost + cards[k].cost <= T) {
						System.out.println(cards[i].name + " " + cards[j].name + " " + cards[k].name);
					}
				}
			}
		}

	}

}