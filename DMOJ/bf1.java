package DMOJ;
import java.util.Arrays;
import java.util.Scanner;

public class List_Minimum {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int size = in.nextInt();
		
		int[] nums = new int[size];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = in.nextInt();
		}
		Arrays.sort(nums);
		
		for (int i : nums) {
			System.out.println(i);
		}
	}

}
