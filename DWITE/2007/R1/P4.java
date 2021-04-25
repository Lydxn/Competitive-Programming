import java.io.*;
import java.util.*;

public class P4 {
    static int[] blocks;
	static int min = Integer.MAX_VALUE;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int H = in.nextInt();
		int S = in.nextInt();

		blocks = new int[S];
		for (int i = 0; i < blocks.length; i++) {
			blocks[i] = in.nextInt();
		}

		subSum(blocks, 0, 0, H, 0);
		System.out.println(min == Integer.MAX_VALUE ? 0 : min);
	}

	private static void subSum(int[] blocks, int pos, int sum, int goal, int size) {
		if (pos >= blocks.length) {
			if (sum == goal) {
				min = Math.min(min, size);
			}
			return;
		}
		subSum(blocks, pos + 1, sum + blocks[pos], goal, size + 1);
		subSum(blocks, pos + 1, sum, goal, size);
	}
}
