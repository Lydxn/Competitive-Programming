package DMOJ;
import java.util.Scanner;

public class Rabbit_Girls {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		
		int mod = N % K;
		System.out.println(N < K ? K - N : Math.min(mod, K - mod));
	}

}