import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String encrypted = in.nextLine();

		String decrypted = "";
		String key = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for (int i = 0; i < encrypted.length(); i++) {
			decrypted += key.charAt(key.indexOf(encrypted.charAt(i)) + 9);
		}
		System.out.println(decrypted);
	}
}
