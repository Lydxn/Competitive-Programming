package ccc_2011;
import java.util.Arrays;
import java.util.Scanner;

public class J5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int[] friends = new int[N];
		Arrays.fill(friends, 1);
		
		for (int j = 0; j < N - 1; j++) {
			friends[in.nextInt() - 1] *= 1 + friends[j]; 
		}
		System.out.println(friends[N - 1]);	
	}

}
