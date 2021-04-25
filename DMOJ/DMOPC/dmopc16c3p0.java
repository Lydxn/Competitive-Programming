import java.util.Scanner;

public class dmopc16c3p0 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double Vin = in.nextInt();
		double Rf = in.nextInt();
		double Rg = in.nextInt();
		System.out.println(Vin * (1 + Rf / Rg));
	}

}
