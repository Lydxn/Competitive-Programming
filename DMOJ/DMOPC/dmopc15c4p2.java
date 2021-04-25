import java.util.Scanner;

public class DMOPC_2015_C4_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int H = in.nextInt();
		int newM = in.nextInt() + in.nextInt();

		H += newM / 60;
		newM %= 60;
		System.out.println(H % 24 + " " + newM % 60);
	}

}
