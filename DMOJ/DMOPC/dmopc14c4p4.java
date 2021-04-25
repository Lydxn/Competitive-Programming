import java.io.*;
import java.util.*;

public class DMOPC_2014_C4_P4 {

	static final String msg = "HAILHYDRA";

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] encryption = br.readLine().toCharArray();

		Set<String> possible = new HashSet<String>();
		for (int i = 0; i < encryption.length - 8; i++) {
			if (encryption[i] == encryption[i + 4] &&
				encryption[i + 1] == encryption[i + 8]) {
				possible.add(new String(encryption, i, 9));
				i += 9;
			}
		}


		char[] map = new char[91];

		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			String decryption = br.readLine();

			StringBuilder check = new StringBuilder();
			for (int j = 0; j < 9; j++) {
				check.append(decryption.charAt(msg.charAt(j) - 'A'));
			}

			if (possible.contains(check.toString())) {
				for (int j = 0; j < 26; j++) {
					map[decryption.charAt(j)] = (char) (j + 'A');
				}

				for (int j = 0; j < encryption.length; j++) {
					System.out.print(map[encryption[j]]);
				}
				System.out.println();
				return;
			}
		}
		System.out.println("KeyNotFoundError");
	}

}
