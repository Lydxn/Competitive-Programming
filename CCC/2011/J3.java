package ccc_2011;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t1 = in.nextInt();
		int t2 = in.nextInt();
		
		int count = 2;
		while (t1 >= t2 && t1 >= 0 && t2 >= 0) {
			int diff = t1 - t2;
			count++;
			t1 = t2;
			t2 = diff;
		}
		System.out.println(count);
	}

}
