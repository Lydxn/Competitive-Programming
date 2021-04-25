import java.util.Scanner;

public class DMOPC_2015_C5_P2 {

	static final String[] names = {"Okabe", "Mayuri", "Daru", "Kurisu"};
	static final String[] tagline = {"elpsycongroo", "tuturu", "superhacker", "myfork"};

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();

		for (int i = 0; i < N; i++) {
			String message = in.nextLine();

			int senders = 0;
			for (int j = 0; j < names.length; j++) {
				if (isSubsequence(message, tagline[j])) {
					System.out.print((senders++ == 0 ? "" : " or ") + names[j]);
				}
			}
			System.out.println(senders == 0 ? "SERN spy!" : "");
		}
	}

	private static boolean isSubsequence(String s1, String s2) {
		int j = 0;
		for (int i = 0; i < s1.length() && j < s2.length(); i++) {
			if (s1.charAt(i) == s2.charAt(j)) {
				j++;
			}
		}
		return j == s2.length();
	}

}
