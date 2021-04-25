import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[] nums = new int[N];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = in.nextInt();
		}
		
		int wild = 0;
		int prev = 1;
		boolean found = false;
		
		for (int i : nums) {
			if (i == 0) {
				if (wild == 0) {
					found = true;
					continue;
				}
				i = wild;
			} else if (found && wild == 0) {
				wild = i;
			}
			
			if (prev > i) {
				System.out.println("NO");
				return;
			}
			prev = i;
		}
		System.out.println("YES");
	}
}
