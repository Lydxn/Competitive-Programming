package COCI;
import java.util.Scanner;

public class COCI_2007_C3_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String binary = in.nextLine();
		
		while (binary.length() % 3 != 0) {
			binary = "0" + binary;
		}
		
		for (int i = 0; i < binary.length(); i += 3) {
			System.out.print(Integer.toString(Integer.parseInt(binary.substring(i, i + 3), 2), 8));
		}
	}

}