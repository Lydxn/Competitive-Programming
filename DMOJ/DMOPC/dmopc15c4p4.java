import java.util.*;

public class DMOPC_2015_C4_P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		int Q = in.nextInt();

		@SuppressWarnings("unchecked")
		TreeSet<Integer>[] nums = new TreeSet[2001];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = new TreeSet<Integer>();
		}

		int[] prefix = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			int num = in.nextInt();
			prefix[i] = num + prefix[i - 1];
			nums[num + 1000].add(i);
		}

		for (int i = 0; i < Q; i++) {
			int a = in.nextInt(), b = in.nextInt(), x = in.nextInt(), y = in.nextInt();

			Integer searchA = nums[a + 1000].floor(y);
			Integer searchB = nums[b + 1000].floor(y);
			System.out.println(prefix[y] - prefix[x - 1] > K &&
							   searchA != null && searchB != null && searchA >= x && searchB >= x
							   ? "Yes" : "No");
		}
	}

}
