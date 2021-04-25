package DMOJ;
import java.util.Scanner;

public class A20_Gate {
	
	static final int A20 = 1 << 20;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String address = in.nextLine();
			long dec = Long.parseLong(address, 16);
			
			if ((dec & A20) != 0) {
				System.out.format("%08X %08X\n", dec ^ A20, dec);
			} else {
				System.out.format("%08X\n", dec);
			}
		}
	}
	
}
