package euler100;

public class P017 {

	public static void main(String[] args) {
		int units = 3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4;
		int teens = 3 + 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8;
		int tens = 6 + 6 + 5 + 5 + 5 + 7 + 6 + 6;
		int twoDigit = 9 * units + teens + 10 * tens; 
				
		System.out.println(10 * twoDigit + 
						   100 * units + 
						   900 * "hundred".length() + 
						   891 * "and".length() +
						   "one".length() +
						   "thousand".length());
	}

}
