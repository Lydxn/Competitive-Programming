import java.io.*;
import java.util.*;

public class P4 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			System.out.println(toDecimal(in.nextLine()));
		}
	}

	private static int toDecimal(String roman) {
		int amount = 0;
		int result = 0;
		int preAmount = 1001;

		for (int i = 0; i < roman.length(); i++) {
			char numeral = roman.charAt(i);
			switch (numeral) {
				case 'I': amount = 1;
						  break;
				case 'V': amount = 5;
						  break;
				case 'X': amount = 10;
					      break;
				case 'L': amount = 50;
						  break;
				case 'C': amount = 100;
						  break;
				case 'D': amount = 500;
						  break;
				case 'M': amount = 1000;
						  break;
			}

			result += amount > preAmount ? amount - 2 * preAmount : amount;
			preAmount = amount;
		}
		return result;
	}
}
