package euler100;
import java.util.ArrayList;

public class P024 {

	public static void main(String[] args) {
		int order = 999999;
		String perm = "";
		
		ArrayList<Integer> nums = new ArrayList<Integer>();
		for (int i = 0; i <= 9; i++) {
			nums.add(i);
		}
		
		for (int i = 9; i >= 0; i--) {
			int quotient = order / fact(i);
			order %= fact(i);
			perm += nums.get(quotient);
			nums.remove(quotient);
		}
		System.out.println(perm);
	}
	
	private static int fact(int n) {
		int prod = 1;
		for (int i = 2; i <= n; i++) {
			prod *= i;
		}
		return prod;
	}
	
}
