package DMOJ;
import java.util.Scanner;

public class Inaho_VI {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long x = in.nextLong();
		
		double real = 1;
		double imag = 0;
		double temp = 0;
		double part = 0;
		
		for (int i = 1; i <= Math.min(x, 86); i++) {
			part = Math.pow(Math.E, -Math.PI * imag / 2);
			temp = real;
			
			real = part * Math.cos(Math.PI * temp / 2);
			imag = part * Math.sin(Math.PI * temp / 2);
		}
		System.out.println(round10000th(real) + " " + round10000th(imag));
	}	
	
	private static String round10000th(double n) {
		return String.format("%.4f", n);
	}

}