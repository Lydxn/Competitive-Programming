package DMOJ;
import java.util.Scanner;

public class Arranged_Marriage {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
    	long N = in.nextLong();
    	int B = in.nextInt();
		int A = in.nextInt();
		
	    long increase = Math.round((double) (B * N - A) / (2 * B));
		long res = (A + B * increase) * (N - increase);
		
		System.out.println(res < 0 ? A * N : res);
	}

}