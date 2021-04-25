import java.util.Scanner;

public class dmopc16c1p0 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int W = in.nextInt();
		int C = in.nextInt();
		System.out.println("C.C. is " + (W == 3 && C >= 95 ? "absolutely" : (W == 1 && C <= 50 ? "fairly" : "very")) + " satisfied with her pizza.");
	}

}
