package DMOJ;
import java.io.*;
import java.util.Arrays;

public class List_Minimum_Hard {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int size = Integer.parseInt(br.readLine());
		
		Integer[] nums = new Integer[size];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(nums);
		
		for (int i : nums) {
			System.out.println(i);
		}
	}

}