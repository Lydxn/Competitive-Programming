package ccc_2007;
import java.util.Arrays;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] weights = {in.nextInt(), in.nextInt(), in.nextInt()};	
		Arrays.sort(weights);
		System.out.println(weights[1]);
	}
		
}
