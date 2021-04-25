import java.io.*;
import java.util.*;

public class utso18p2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

		int[][] ABC = new int[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				ABC[i][j] = in.nextInt();
			}
		}

		int sum = 0;
		for (int k = 0; k < 3; k++) {
			if (ABC[1][k] == ABC[0][Math.floorMod(k - 1, 3)] && ABC[2][k] >= 0) {
				sum += ABC[2][k];
			}
		}
		System.out.println(sum);
    }
}
