package ccc_2013;
import java.util.Scanner;

public class S2 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int W = in.nextInt();
		int N = in.nextInt();
		
		int[] cars = new int[3];
		for (int j = 0; j < N; j++) {
			int temp = in.nextInt();
			if (temp + cars[0] + cars[1] + cars[2] > W) {
				System.out.println(j);
				return;
			}
			
			cars[2] = cars[1];
			cars[1] = cars[0];
			cars[0] = temp;
		}
		System.out.println(N);
	}
	
}
