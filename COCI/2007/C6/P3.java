package COCI;
import java.util.Scanner;

public class COCI_2007_C6_P3 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[] plates = new int[N];
		int min = Integer.MAX_VALUE;
		
		for (int i = 0; i < N; i++) {
			plates[i] = in.nextInt();
			min = Math.min(min, plates[i]);
		}
		
		int[] diff = new int[N - 1];
		for (int i = 0, j = 0; i < plates.length; i++) {
			if (plates[i] != min) {
				diff[j++] = plates[i] - min;
			}
		}
		
		int gcd = diff[0];
		for (int i = 1; i < diff.length; i++) {
			gcd = gcd(gcd, diff[i]);
		}

		for (int i = 2; i * i <= gcd; i++) {
			if (gcd % i == 0) {
				System.out.print(i + " ");
				if (gcd / i != i) {
					System.out.print(gcd / i + " ");
				}
			}
		}
		System.out.println(gcd);
	}
	
	private static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
}