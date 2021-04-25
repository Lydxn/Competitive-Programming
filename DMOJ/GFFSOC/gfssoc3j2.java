package DMOJ;
import java.util.Scanner;

public class Purchasing_Presents {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		double C = in.nextDouble();
		
		double sum = 0;
		for (int i = 0; i < N; i++) {
			sum += in.nextDouble();
		}
		System.out.println(sum > C ? "Fardin's broke" : String.format("%.2f", C - sum));
	}

}