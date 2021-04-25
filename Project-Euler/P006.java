package euler100;

public class P006 {

	public static void main(String[] args) {
		int n = 100;
		int sum = n * (n + 1) * (2 * n + 1) / 6;
		int square = (int) Math.pow(n * (n + 1) / 2, 2);
		System.out.println(Math.abs(square - sum));
	}

}

