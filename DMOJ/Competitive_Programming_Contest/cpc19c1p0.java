import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String shoes = in.nextLine().replace(" ", "");

		int L1 = shoes.indexOf('L') + 1;
		int L2 = shoes.lastIndexOf('L') + 1;
		int R1 = shoes.indexOf('R') + 1;
		int R2 = shoes.lastIndexOf('R') + 1;
		System.out.println(L1 + " " + R1 + "\n" + L2 + " " + R2);
	}
}
