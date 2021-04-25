package DMOJ;

import java.util.Scanner;

public class Waiting {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String[] griffy = in.nextLine().split(":");
		String[] school = in.nextLine().split(":");
		
		int gSecs = toInt(griffy[0]) * 3600 + toInt(griffy[1]) * 60 + toInt(griffy[2]);
		int sSecs = toInt(school[0]) * 3600 + toInt(school[1]) * 60 + toInt(school[2]);
		System.out.println(sSecs - gSecs);
	}
	
	private static int toInt(String str) {
		return Integer.parseInt(str);
	}

}