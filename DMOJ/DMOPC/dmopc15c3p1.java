import java.util.Scanner;

public class DMOPC_2015_C3_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		System.out.println((c < b && d >= b) || (a < d && b >= d) ? "YES" : "NO");
	}

}
