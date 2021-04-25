import java.util.*;
import java.io.*;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		in.nextLine();

		for (int i = 0; i < tests; i++) {
			String bday = in.nextLine();
			System.out.println(SDR(bday));
		}
	}

	private static String SDR(String bday) {
		if (bday.length() == 1) {
			return bday;
		} else {
			int sum = 0;
			while (bday.length() > 0) {
				int len = bday.length();
				sum += Integer.parseInt(bday.substring(len - 1, len));
				bday = bday.substring(0, len - 1);
			}
			return SDR(Integer.toString(sum));
		}
	}

}
