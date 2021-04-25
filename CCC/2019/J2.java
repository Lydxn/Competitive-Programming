import java.util.Collections;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int L = in.nextInt();
		
		for (int i = 0; i < L; i++) {
			int N = in.nextInt();
			String x = in.next();
			
			System.out.println(String.join("", Collections.nCopies(N, x)));
		}
	}

}
