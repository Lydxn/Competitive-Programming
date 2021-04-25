import java.util.Scanner;

public class P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			String str = in.nextLine();
			for (int j = 0; j < str.length(); j++) {
				char ch = str.charAt(j);
				if (str.indexOf(ch) == str.lastIndexOf(ch)) {
					System.out.println(ch);
					break;
				}
			}
		}
	}

}
