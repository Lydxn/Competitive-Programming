import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String S = br.readLine();

		String pusheen = "pusheen";
		int errors = 0;

		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) != pusheen.charAt(i)) {
				errors++;
			}
		}
		System.out.println(errors);
    }
}
