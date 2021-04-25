package COCI;
import java.util.Scanner;

public class COCI_2006_C6_P5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long X = in.nextLong();
		long A = in.nextLong();
		long B = in.nextLong();
		in.nextLine();
		String allowed = in.nextLine();
		
		int count = 0;
	    long rem = (A + X) % X;
		outer: for (long i = rem == 0 ? A : A + X - rem; i <= B; i += X) {
			String s = Long.toString(i);
			for (int j = 0; j < s.length(); j++) {
			    if (allowed.indexOf(s.charAt(j)) == -1) {
			        continue outer;
			    }
			}
			count++;
		}
		System.out.println(count);
	}
	
}