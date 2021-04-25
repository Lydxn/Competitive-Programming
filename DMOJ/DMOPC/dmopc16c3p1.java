import java.util.Scanner;

public class dmopc16c3p1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N1 = in.nextInt();
		in.nextLine();
		String S = in.nextLine();
		int N2 = in.nextInt();
		System.out.println(S.equals("Infront") ? N1 - N2 : N1 + N2);
	}

}
