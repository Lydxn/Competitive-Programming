package DMOJ;
import java.util.Scanner;

public class Binary {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		for (int i = 0; i < N; i++) {
			System.out.println(toBinaryString(in.nextInt()));
		}
	}
 	
	private static String toBinaryString(int decimal) {
	    StringBuilder res = new StringBuilder();
	    for (int i = (Integer.toBinaryString(decimal).length() + 3) / 4 * 4 - 1; i >= 0; i--) {
	    	res.append((decimal & (1 << i)) != 0 ? "1" : "0");
	    	if ((i & 3) == 0) {
	    		res.append(" ");
	    	}
	    }
	    return res.toString();
	}

}