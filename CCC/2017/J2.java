package ccc_2017;
import java.util.Scanner;

public class J2 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int k = in.nextInt();
		
		long total = N;
		for (int i = 1; i <= k; i++) {
			int temp = (int) (N * Math.pow(10, i));
			total += temp;
		}
		
		System.out.println(total);
	}
	
}
