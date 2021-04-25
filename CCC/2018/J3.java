package ccc_2018;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		
		int AB = a;
		int AC = a + b;
		int AD = a + b + c;
		int AE = a + b + c + d;
		int BC = b;
		int BD = b + c;
		int BE = b + c + d;
		int CD = c;
		int CE = c + d;
		int DE = d;
		
		System.out.println("0 " + AB + " " + AC + " " + AD + " " + AE);
		System.out.println(AB + " 0 " + BC + " " + BD + " " + BE);
		System.out.println(AC + " " + BC + " 0 " + CD + " " + CE);
		System.out.println(AD + " " + BD + " " + CD + " 0 " + DE);
		System.out.println(AE + " " + BE + " " + CE + " " + DE + " 0 ");
	}

}
