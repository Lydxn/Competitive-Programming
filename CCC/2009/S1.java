package ccc_2009;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		
		int count = 0;
		for (int i = 1; i <= 21; i++) {
			double power6 = Math.pow(i, 6); 
			if (power6 <= b && power6 >= a) {
				count++;
			}
		}
		System.out.println(count);
	}

}
