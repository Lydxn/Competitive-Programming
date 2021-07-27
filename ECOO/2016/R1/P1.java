package ECOO;
import java.util.Scanner;

public class ECOO_2016_R1_P1 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int[] weights = new int[4];
			for (int j = 0; j < weights.length; j++) {
				weights[j] = in.nextInt();
			}
			
			int N = in.nextInt();
			double[] marks = new double[N];
			
			for (int j = 0; j < marks.length; j++) {
				for (int k = 0; k < 4; k++) {
					marks[j] += in.nextInt() * weights[k];
				}
			}
			
			int passed = 0;
			for (double j : marks) {
				if (j >= 5000) {
					passed++;
				}
			}
			System.out.println(passed);
		}
	}

}