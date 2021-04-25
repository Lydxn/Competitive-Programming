import java.io.*;
import java.util.*;

public class P3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String dvorak = br.readLine();

		String[] convert = {" ", "!", "Q", "#", "$", "%", "&", "q", "(", ")", "*", "}", "w", "\'", "e", "[",
							"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Z", "z", "W", "]", "E", "{",
							"@", "A", "N", "I", "H", "D", "Y", "U", "J", "G", "C", "V", "P", "M", "L", "S",
							"R", "X", "O", ":", "K", "F", ">", "<", "B", "T", "?", "-", "\\", "=", "^", "\"",
							"`", "a", "n", "i", "h", "d", "y", "u", "j", "g", "c", "v", "p", "m", "l", "s",
							"r", "x", "o", ";", "k", "f", ".", ",", "b", "t", "/", "_", "|", "+", "~"};

		String qwerty = "";
		for (int i = 0; i < dvorak.length(); i++) {
			qwerty += convert[dvorak.charAt(i) - 32];
		}
		System.out.println(qwerty);
    }
}
