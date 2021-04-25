import java.util.Scanner;

public class P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int[] sums = new int[5];
			for (int j = 0; j < sums.length; j++) {
				sums[j] = in.nextInt() + in.nextInt();
			}

			int count = 0;
			for (int s : sums) {
				if (s == in.nextInt()) count++;
			}
			System.out.println(count);
		}
	}

}
