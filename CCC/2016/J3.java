package ccc_2016;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
        String palin = in.nextLine();
        
        int max = 1;
        for (int i = 0; i < palin.length() - 1; i++) {
            for (int j = i + 1; j < palin.length(); j++) {
            	if (isPalin(palin.substring(i, j + 1))) {
            		max = Math.max(max, j - i + 1);
            	}
            }
        }
        System.out.println(max);
    }
	
	private static boolean isPalin(String str) {
		for (int i = 0; i < str.length() / 2; i++) {
			if (str.charAt(i) != str.charAt(str.length() - i - 1)) {
				return false;
			}
		}
		return true;
	}

}
