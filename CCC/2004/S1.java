package ccc_2004;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String a = in.nextLine();
			String b = in.nextLine();
			String c = in.nextLine();
			
			System.out.println((pre(a, b) || pre(b, c) || pre(a, c) || suf(a, b) || suf(b, c) || suf(a, c)) ? "No" : "Yes");
		}
	}
	
	private static boolean pre(String s1, String s2) {
		return s1.indexOf(s2) == 0 || s2.indexOf(s1) == 0;
	}
	
	private static boolean suf(String s1, String s2) {
		return (s1.indexOf(s2) == s1.length() - s2.length() && s1.indexOf(s2) >= 0) || 
			   (s2.indexOf(s1) == s2.length() - s1.length() && s2.indexOf(s1) >= 0);
	}

}
