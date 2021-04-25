package ccc_2012;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String aro = in.nextLine();
		
		int ans = 0;
		for (int i = 0; i < aro.length(); i += 2) {
			int temp = arabic(aro.charAt(i + 1));
			if (i + 2 >= aro.length() || (i + 2 < aro.length() && temp >= arabic(aro.charAt(i + 3)))) {
				ans += (aro.charAt(i) - 48) * temp;
			} else {
				ans -= (aro.charAt(i) - 48) * temp;
			}
		}
		System.out.println(ans);
	}
	
	public static int arabic(char roman) {
		int[] A = {1, 5, 10, 50, 100, 500, 1000};
		String R = "IVXLCDM";
		
		return A[R.indexOf(roman)];
	}

}
