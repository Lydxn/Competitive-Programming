package DMOJ;
import java.util.Scanner;

public class Uneven_Sand {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
			
		long low = 1;
		long high = 2000000000;
    		long mid = (low + high) / 2;
		
		while (true) {
			System.out.println(mid);
			System.out.flush();
			String res = in.nextLine();
			
			if (res.equals("SINKS")) {
				low = mid;
				mid = (mid + high) / 2;
			} else if (res.equals("FLOATS")) {
				high = mid;
				mid = (mid + low) / 2;
			} else {
				return;
			}
		}
	}

}
