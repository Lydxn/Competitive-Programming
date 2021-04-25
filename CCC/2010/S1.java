package ccc_2010;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();

		int maxForm1 = 0;
		int maxForm2 = 0;
		String maxName1 = "";
		String maxName2 = "";
		
		for (int i = 0; i < n; i++) {
			String name = in.next();
			int R = in.nextInt();
			int S = in.nextInt();
			int D = in.nextInt();
			
			int formula = 2 * R + 3 * S + D;
			if ((formula > maxForm1) || (formula == maxForm1 && name.compareTo(maxName1) < 0)) {
				maxForm2 = maxForm1;
				maxForm1 = formula;
				
				maxName2 = maxName1;
				maxName1 = name;
			} else if ((formula > maxForm2) || (formula == maxForm2 && name.compareTo(maxName2) < 0)) {
				maxForm2 = formula;
				maxName2 = name;
			}
		}
		
		System.out.println(maxName1);
		System.out.println(n == 1 ? "" : maxName2);
	}

}
