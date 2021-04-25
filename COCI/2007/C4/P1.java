package COCI;
import java.util.Scanner;

public class COCI_2007_C4_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int A = in.nextInt();
		int B = in.nextInt();
		int C = in.nextInt();
		int D = in.nextInt();
		
		for (int i = 0; i < 3; i++) {
			int man = in.nextInt();
			
			if (man % (A + B) <= A && man % (A + B) > 0 && man % (C + D) <= C && man % (C + D) > 0) {
				System.out.println("both");
			} else if ((man % (A + B) <= A && man % (A + B) > 0) || (man % (C + D) <= C && man % (C + D) > 0)) {
				System.out.println("one");
			} else {
				System.out.println("none");
			}
		}
	}

}