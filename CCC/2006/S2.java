package ccc_2006;
import java.util.HashMap;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String plaintext = in.nextLine();
		String transcipher = in.nextLine();
		String ciphertext = in.nextLine();
		
		HashMap<Character, Character> decode = new HashMap<Character, Character>();
		for (int i = 0; i < plaintext.length(); i++) {
			decode.put(transcipher.charAt(i), plaintext.charAt(i));
		}
		
		String decipher = "";
		for (int i = 0; i < ciphertext.length(); i++) {
			decipher += !decode.containsKey(ciphertext.charAt(i)) ? '.' : decode.get(ciphertext.charAt(i));
		}
		System.out.println(decipher);
	}

}
