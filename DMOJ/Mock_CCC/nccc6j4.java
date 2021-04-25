import java.io.*;
import java.util.*;

class Order {
	String food;
	int amount;

	public Order(String food, int amount) {
		this.food = food;
		this.amount = amount;
	}
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		ArrayList<String> foods = new ArrayList<String>(Arrays.asList("Deluxe Tuna Bitz", "Bonito Bitz", "Sashimi", "Ritzy Bitz"));
		Order[] orders = new Order[4];
		orders[0] = new Order("Deluxe Tuna Bitz", 0);
		orders[1] = new Order("Bonito Bitz", 0);
		orders[2] = new Order("Sashimi", 0);
		orders[3] = new Order("Ritzy Bitz", 0);

		for (int i = 0; i < N; i++) {
			String food = br.readLine();
			orders[foods.indexOf(food)].amount++;
		}

		Arrays.sort(orders, new Comparator<Order>() {
			public int compare(Order a, Order b) {
				Integer aAmount = a.amount;
				Integer bAmount = b.amount;
				return bAmount.compareTo(aAmount);
			}
		});

		int zero = 0;
		for (; zero < orders.length; zero++) {
			if (orders[zero].amount == 0) {
				break;
			}
		}
		orders = Arrays.copyOfRange(orders, 0, zero);

		for (int i = 0; i < orders.length; i++) {
			for (int j = 0; j < orders.length - i - 1; i++) {
				if (orders[j].amount == orders[j + 1].amount && foods.indexOf(orders[j].food) > foods.indexOf(orders[j + 1].food)) {
					Order temp = orders[j];
					orders[j] = orders[j + 1];
					orders[j + 1] = temp;
				}
			}
		}

		for (Order o : orders) {
			System.out.println(o.food + " " + o.amount);
		}
	}
}
