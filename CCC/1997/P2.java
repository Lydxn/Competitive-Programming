package ccc_1997;
import java.util.HashSet;
import java.util.Scanner;

public class P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int following = in.nextInt();
		
		for (int i = 0; i < following; i++) {
			int num = in.nextInt();
			System.out.println(num + " is " + (isNasty(num) ? "nasty" : "not nasty"));
		}
	}

	private static boolean isNasty(int n) {
		HashSet<Integer> nums = new HashSet<Integer>();
		
		for (int i = 1; i * i < n; i++) {
			if (n % i == 0) {
				int temp = nums.size();
				nums.add(i + n / i);
				
				nums.add(Math.abs(i - n / i));
				if (nums.size() != temp + 2) {
					return true;
				}
			}
		}
		return false;
	}

}
