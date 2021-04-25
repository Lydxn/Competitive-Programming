package ccc_1996;
import java.util.Scanner;

public class P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String romanEq = in.nextLine();
			int roman1 = toDecimal(romanEq.substring(0, romanEq.indexOf("+")));
			int roman2 = toDecimal(romanEq.substring(romanEq.indexOf("+") + 1, romanEq.length() - 1));
			System.out.println(romanEq + (roman1 + roman2 > 1000 ? "CONCORDIA CUM VERITATE" : toRoman(roman1 + roman2)));
		}
	}
	
	private static int toDecimal(String roman) {
		int amount = 0;
		int result = 0;
		int preAmount = 1001;
		
		for (int i = 0; i < roman.length(); i++) {
			char numeral = roman.charAt(i);
			switch (numeral) {
			case 'I': 
				amount = 1;
				break;
			case 'V': 
				amount = 5;
				break;
			case 'X': 
				amount = 10;
				break;
			case 'L': 
				amount = 50;
				break;
			case 'C': 
				amount = 100;
				break;
			case 'D': 
				amount = 500;
				break;
			case 'M': 
				amount = 1000;
				break;
			}

			result += amount > preAmount ? amount - 2 * preAmount : amount;
			preAmount = amount;
		}
		return result;
	}

	private static String toRoman(int decimal) {
		int[] dValues = {1000, 900, 800, 700, 600, 500, 400, 300, 200, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		String[] rValues = {"M", "CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C", "XC", "LXXX", "LXX", "LX", "L", "XL", "XXX", "XX", "X", "IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I"};
		
		String result = "";
		for (int i = 0; i < 28; i++) {
			while (decimal >= dValues[i]) {
				decimal -= dValues[i];
				result += rValues[i];
			}
		}
		return result;
	}

}
