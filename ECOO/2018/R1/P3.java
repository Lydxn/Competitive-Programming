package ECOO;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ECOO_2018_R1_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int N = in.nextInt();
			int X = in.nextInt();
			int Y = in.nextInt();
			int Z = in.nextInt();
			in.nextLine();
			
			List<Integer> fails = new ArrayList<Integer>();
			String[] decoded = new String[N]; 
			
			for (int j = 0; j < N; j++) {
				decoded[j] = convert(in.nextLine(), X, Y, Z);
			}
			in.nextLine();
			
			for (int j = 0; j < N; j++) {
				if (!decoded[j].equals(in.nextLine())) {
					fails.add(j + 1);
				}
			}
			
			if (fails.isEmpty()) {
				System.out.println("MATCH");
			} else {
				String res = "";
				for (int f : fails) {
					res += f + " ";
				}
				System.out.println("FAIL: " + res.trim().replace(" ", ","));
			}
			in.nextLine();
		}
	}
	
	private static String convert(String code, int X, int Y, int Z) {
		String res = "";
		for (int i = 0; i < code.length(); i++) {
			int rep; 
			int ch = Character.getNumericValue(code.charAt(i));
			if (ch == 0) {
				rep = Z;
			} else if ((ch & 1) == 0) {
				rep = ch + X;
			} else {
				rep = ch - Y < 0 ? 0 : ch - Y;
			}
			res += Integer.toString(rep) == "0" ? Z : Integer.toString(rep);
		}
		return res;
	}

}