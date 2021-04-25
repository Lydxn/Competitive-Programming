package ccc_2010;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		
		char[] letters = new char[k];
		String[] code = new String[k];
		for (int i = 0; i < k; i++) {
			letters[i] = in.next().charAt(0);
			code[i] = in.next();
		}
		
		String sequence = in.next();
		String ans = "";
		
		while (sequence.length() > 0) {
			int j = 0;
			while (!sequence.startsWith(code[j])) {
				j++;
			}
			
			ans += letters[j];
			sequence = sequence.substring(code[j].length());
		}
		System.out.println(ans);
	}

}
