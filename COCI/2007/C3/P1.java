package COCI;
import java.util.Arrays;
import java.util.Scanner;

public class COCI_2007_C3_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int[] nums = new int[3];
		for (int i = 0; i < 3; i++) {
			nums[i] = in.nextInt();
		}
		Arrays.sort(nums);
		
		int diff1 = nums[1] - nums[0];
		int diff2 = nums[2] - nums[1];
		
		if (diff1 > diff2) {
			System.out.println(nums[0] + diff2);
		} else if (diff1 < diff2) {
			System.out.println(nums[1] + diff1);
		} else if (diff1 == diff2) {
			System.out.println(nums[2] + diff1);
		}
	}

}