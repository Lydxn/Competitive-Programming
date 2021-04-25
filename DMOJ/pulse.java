package DMOJ;
import java.util.Scanner;

public class Pulse {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int S = in.nextInt();
		int T = in.nextInt();
		
		int recieved = 0;
		for (int i = 0; i < N; i++) {
			int time = in.nextInt() * 2;
			if (time >= S && time <= T) {
				recieved++;
			}
		}
		System.out.println(recieved);
	}

}
