package ccc_2003;
import java.util.Scanner;

public class S2_J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String[] poem = new String[4];
			for (int j = 0; j < 4; j++) {
				poem[j] = lastSyl(in.nextLine());
			}
			
			if (poem[0].equals(poem[1]) && poem[1].equals(poem[2]) && poem[2].equals(poem[3])) {
				System.out.println("perfect");
			} else if (poem[0].equals(poem[1]) && poem[2].equals(poem[3])) {
				System.out.println("even");
			} else if (poem[0].equals(poem[2]) && poem[1].equals(poem[3])) {
				System.out.println("cross");
			} else if (poem[0].equals(poem[3]) && poem[1].equals(poem[2])) {
				System.out.println("shell");
			} else {
				System.out.println("free");
			}
		}
	}

	private static String lastSyl(String line) {
		String result = "";
		String vowels = "aeiouAEIOU ";
		
		for (int i = line.length() - 1; i >= 0; i--) {
			char c = line.charAt(i);
			if (vowels.indexOf(c) >= 0) {
				return (result + c).toLowerCase(); 
			}
			result += c;
		}
		return result.toLowerCase();
	}

}
