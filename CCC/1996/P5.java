package ccc_1996;
import java.util.Scanner;

public class P5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sets = in.nextInt();
		for (int i = 0; i < sets; i++) {
			int seqLen = in.nextInt();
			int[] X = new int[seqLen];
			int[] Y = new int[seqLen];
			
			for (int j = 0; j < seqLen; j++) {
				X[j] = in.nextInt();
			}
			
			for (int k = 0; k < seqLen; k++) {
				Y[k] = in.nextInt();
			}
			
			int maxDist = 0;
			for (int x = 0; x < seqLen; x++) {
				for (int y = x; y < seqLen; y++) {
					if (Y[y] >= X[x]) {
						maxDist = Math.max(maxDist, y - x);
					} else {
						break;
					}
				}
			}
			System.out.println("The maximum distance is " + maxDist + "\n");
		}
	}

}
