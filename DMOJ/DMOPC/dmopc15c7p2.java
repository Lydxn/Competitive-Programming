import java.util.Scanner;

public class DMOPC_2015_C7_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String text = in.nextLine();

		int spaces = 0;
		for (int i = 0; i < text.length(); i++) {
			if (text.charAt(i) == ' ') {
				spaces++;
			}
		}
		System.out.println(spaces + 1);
	}

}
