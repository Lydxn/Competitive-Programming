package ccc_2002;
import java.util.Scanner;

public class J2 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			String AtoC = in.nextLine();
			
			if (AtoC.equals("quit!")) {
				return;
			}
			
			int len = AtoC.length();
			if (len > 4 && !("aeiouy".contains(AtoC.substring(len - 3, len - 2))) && AtoC.substring(len - 2).equals("or")) {
				System.out.println(AtoC.substring(0, len - 1) + "ur");
			} else {
				System.out.println(AtoC);
			}
		}
	}

}
