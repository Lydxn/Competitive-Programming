package DMOJ;
import java.util.Scanner;

public class Infinity {

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int hex1 = Integer.parseInt(in.nextLine(), 16);
		int hex2 = Integer.parseInt(in.nextLine(), 16);
		System.out.println(hex1 + hex2 > 0x3F3F3F3F ? "Yes" : "No");
    }

}
