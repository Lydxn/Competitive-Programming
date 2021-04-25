package COCI;
import java.util.Scanner;

public class COCI_2007_C6_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int L = in.nextInt();
		
		int[][] lights = new int[N][3];
		for (int i = 0; i < N; i++) {
			lights[i][0] = in.nextInt();
			lights[i][1] = in.nextInt();
			lights[i][2] = in.nextInt();
		}
		
		int time = 0;
		for (int j = 0; j < lights.length; j++) {
			time = j == 0 ? lights[j][0] : time + lights[j][0] - lights[j - 1][0];

			int R = lights[j][1];
			int G = lights[j][2];
			if (time % (R + G) < R) {
				time += R - time % (R + G);
			}
			
		}
		System.out.println(time + L - lights[N - 1][0]);
	}

}