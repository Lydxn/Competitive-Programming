package DMOJ;
import java.util.Scanner;

public class Dupvoting {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int P = in.nextInt();
		int U = in.nextInt();
		int R1 = in.nextInt();
		int R2 = in.nextInt();
		
		double ratio = (double) R1 / R2;
		int triplets = 0;
		
		for (int dup = 0; dup <= 1000; dup++) {
			for (int up = 0; up <= 1000; up++) {
				double downD = U - dup - up;
				if (2 * dup + up - downD == P) {
					double dupD = dup;
					double upD = up;
					
					if (dupD / downD == ratio || downD / dupD == ratio || 
						dupD / upD == ratio || upD / dupD == ratio ||
						downD / upD == ratio || upD / downD == ratio) {
						triplets++;
					}
				}
			}
		}
		System.out.println(triplets);
	}

}
