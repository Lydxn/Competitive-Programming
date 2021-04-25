package DMOJ;
import java.util.Scanner;

public class Speech {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		String[][] words = new String[N][2];
		for (int i = 0; i < N; i++) {
			words[i] = in.nextLine().split(" ");
		}

		String speech = in.nextLine();
		for (String[] w : words) {
			speech = speech.replaceAll("\\b" + w[1] + "\\b", w[0]);
		}
		System.out.println(speech);
	}

}