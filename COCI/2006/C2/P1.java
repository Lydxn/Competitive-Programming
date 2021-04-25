package COCI;
import java.util.Scanner;

public class COCI_2006_C2_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int R1 = in.nextInt();
		int S = in.nextInt();
		
		int R2 = 2 * S - R1;
		System.out.println(R2);
	}

}
