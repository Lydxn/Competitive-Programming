package ccc_2005;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < t; i++) {
			String alphaNum = in.nextLine();
			String numericNum = "";
			
			for (int j = 0; j < alphaNum.length() && numericNum.length() < 10; j++) {
				char c = alphaNum.charAt(j);
				
				if (c >= 65 && c <= 67) {
					numericNum += "2";
				} else if (c >= 68 && c <= 70) {
					numericNum += "3";
				} else if (c >= 71 && c <= 73) {
					numericNum += "4";
				} else if (c >= 74 && c <= 76) {
					numericNum += "5";
				} else if (c >= 77 && c <= 79) {
					numericNum += "6";
				} else if (c >= 80 && c <= 83) {
					numericNum += "7";
				} else if (c >= 84 && c <= 86) {
					numericNum += "8";
				} else if (c >= 87 && c <= 90) {
					numericNum += "9";
				} else if (c != '-') {
					numericNum += c;
				}
			}
			System.out.println(numericNum.substring(0, 3) + "-" + numericNum.substring(3, 6) + "-" + numericNum.substring(6));
		}
	}

}
