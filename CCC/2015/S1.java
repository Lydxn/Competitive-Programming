package ccc_2015;
import java.util.ArrayList;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int K = in.nextInt();
		
		ArrayList<Integer> sequence = new ArrayList<Integer>();
		for (int i = 0; i < K; i++) {
			int num = in.nextInt();
			
			if (num == 0) {
				sequence.remove(sequence.size() - 1);
			} else {
				sequence.add(num);
			}
		}
		
		int sum = 0;
		for (int j = 0; j < sequence.size(); j++) {
			sum += sequence.get(j);
		}
		System.out.println(sum);
	}
}
