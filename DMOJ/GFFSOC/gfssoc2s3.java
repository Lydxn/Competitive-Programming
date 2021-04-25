package DMOJ;
import java.util.Scanner;

public class System_0 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		double c1 = in.nextDouble();
		double c2 = in.nextDouble();
		
		System.out.println(String.format("%.6f", -c2 / c1 / n));
	}

}