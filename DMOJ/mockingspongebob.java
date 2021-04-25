package DMOJ;
import java.util.Scanner;

public class Mocking_SpongeBob {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String L = in.nextLine();

			for (int j = 0, index = 1; j < L.length(); j++, index++) {
				char ch = L.charAt(j);
				System.out.print(index % 2 == 0 ? Character.toUpperCase(ch) : Character.toLowerCase(ch));
				
				if (!Character.isAlphabetic(ch)) {
					index--;
				}
			}
			System.out.println();
		}
	}

}