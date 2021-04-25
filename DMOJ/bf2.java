package DMOJ;
import java.util.Scanner;

public class Lexicographically_Least_Substring {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();
		int K = in.nextInt();
		
		String minLexi = str.substring(0, K);
		for (int i = 1; i < str.length() - K; i++) {
			String sub = str.substring(i, i + K);
			minLexi = minLexi.compareTo(sub) < 0 ? minLexi : sub;
		}
		System.out.println(minLexi);
	}

}
