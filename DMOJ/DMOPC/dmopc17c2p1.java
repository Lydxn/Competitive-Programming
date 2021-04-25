import java.util.Scanner;

public class dmopc17c2p1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		long sum = 0;
		for (int i = 0; i < N; i++) {
			int c = in.nextInt(), v = in.nextInt();
			if (v > 0) {
				sum += c;
			}
		}
		System.out.println(sum);
	}

}
