package ccc_2012;
import java.util.Scanner;

public class J3 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		
		String asterisk = "";
		String x = "";
		String space = "";
		
		for (int i = 0; i < k; i++) {
			asterisk += "*";
			x += "x";
			space += " ";
		}
		
		for (int a = 0; a < k; a++) {
			System.out.println(asterisk + x + asterisk);
		}
		
		for (int b = 0; b < k; b++) {
			System.out.println(space + x + x);	
		}
		
		for (int c = 0; c < k; c++) {
			System.out.println(asterisk + space + asterisk);
		}
	}
	
}
