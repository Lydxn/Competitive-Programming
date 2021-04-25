package euler100;

public class P019 {

	public static void main(String[] args) {
		int sunday = 0;
		int weekdays = 2;
		
		for (int y = 1901; y < 2001; y++) {
			int[] months = {31, y % 4 == 0 ? (y % 100 == 0 ? (y % 400 == 0 ? 29 : 28) : 29) : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			for (int m : months) {
				weekdays += m % 7;
				if (weekdays % 7 == 0) {
					sunday++;
				}
			}
		}
		System.out.println(sunday);
	}

}
