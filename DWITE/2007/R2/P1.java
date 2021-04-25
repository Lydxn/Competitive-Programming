import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int[] nums = new int[5];
		for (int i = 0; i < 5; i++) {
			nums[i] = in.nextInt();
		}

		for (int j = 0; j < 5; j++) {
			int factors = 0;
			for (int k = 2; k <= Math.sqrt(nums[j]); k++) {
				if (nums[j] % k == 0) {
					factors++;
				}
			}
			System.out.println(factors == 1 || factors == 2 ? "semiprime" : "not");
		}
    }
}
