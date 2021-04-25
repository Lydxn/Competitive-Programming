import java.util.Arrays;
import java.util.Scanner;

public class DMOPC_2015_C4_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();

		String[] words = new String[N ];
		for (int i = 0; i < N; i++) {
			words[i] = in.nextLine();
		}
		Arrays.sort(words);

		char prev;
		System.out.print(words[0]);

		for (int i = 1; i < words.length; i++) {
			prev = words[i - 1].charAt(0);
			System.out.print((prev == words[i].charAt(0) ? ", " : "\n") + words[i]);
		}
	}

}
