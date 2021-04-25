import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();

		String alphabet = "abcdefghijklmnopqrstuvwxyz";
		char[] frequency = new char[26];

		for (int i = 0; i < str.length(); i++) {
			frequency[str.charAt(i) - 97]++;
		}
		Arrays.sort(frequency);
		System.out.println(str.length() - (frequency[25] + frequency[24]));
    }
}
