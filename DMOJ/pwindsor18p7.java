package DMOJ;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Going_Back_To_The_Definitions {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		String[] nums = new String[N];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = in.nextLine();
		}
		
		Arrays.sort(nums, new Comparator<String>() {
			public int compare(String A, String B) {
				String AB = A + B;
				String BA = B + A;
				return AB.compareTo(BA);
			}
		});
		
		for (int i = nums.length - 1; i >= 0; i--) {
			System.out.print(nums[i]);
		}
	}

}