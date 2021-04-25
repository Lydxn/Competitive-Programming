package ccc_2018;
import java.util.Arrays;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		double[] village = new double[N];
		for (int i = 0; i < N; i++) {
			village[i] = in.nextDouble();
		}
		Arrays.sort(village);
		
		double smallest = Integer.MAX_VALUE;
		for (int i = 1; i < N - 1; i++) {
			double left = (village[i] + village[i - 1]) / 2;
			double right = (village[i] + village[i + 1]) / 2;
			smallest = Math.min(smallest, right - left);
		}
		System.out.printf("%.1f\n", smallest);
	}

}
