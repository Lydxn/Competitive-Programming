package DMOJ;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class T_Shirts {

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
	
		int[] sizes = new int[3];
		for (int i = 0; i < sizes.length; i++) {
			sizes[i] = in.nextInt();
		}
		
		Deque<Double> costs = new ArrayDeque<Double>();
		for (int s : sizes) {
			double cost = in.nextDouble();
			for (int j = 0; j < s; j++) {
				costs.push(cost);
			}
		}

		double minMoney = 0;
		for (int i = 1; !costs.isEmpty(); i++) {
			minMoney += costs.pollLast();
			if (i % 3 == 0) {
				costs.pollFirst();
			}
		}
		System.out.println(String.format("%.2f", minMoney));
	}

}