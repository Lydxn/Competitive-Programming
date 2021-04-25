package DMOJ;
import java.util.Scanner;

public class German_Nouns {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String line = in.nextLine();
			String[] words = line.split(" ");
			
			int A = 0;
			for (String w : words) {
				if (Character.isUpperCase(w.charAt(0))) {
					A++;
				}
			}
			System.out.println(A);
		}
	}

}
