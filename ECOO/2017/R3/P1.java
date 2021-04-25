package ECOO;
import java.util.Scanner;

public class ECOO_2017_R3_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int F = in.nextInt();
			int D = in.nextInt();
			
			int[][] goods = new int[D][F];
			for (int j = 0; j < D; j++) {
				for (int k = 0; k < F; k++) {
					goods[j][k] = in.nextInt();
				}
			}
			
			int dozens = 0;
			int[][] DF = {{D, F}, {F, D}};
			
			for (int df = 0; df < DF.length; df++) {
				for (int j = 0; j < DF[df][0]; j++) {
					int sum = 0;
					for (int k = 0; k < DF[df][1]; k++) {
						sum += goods[df == 0 ? j : k][df == 0 ? k : j]; 
					}
					
					if (sum % 13 == 0) {
						dozens += sum / 13;
					}
				}
			}
			System.out.println(dozens);
		}
	}

}