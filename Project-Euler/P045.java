package euler100;

public class P045 {

	public static void main(String[] args) {
		for (int i = 144; ; i++) {
			long hexagon = i * (2 * i - 1);
			if (isPentagonal(hexagon)) {
				System.out.println(hexagon);
				return;
			}
		}
	}
	
	private static boolean isPentagonal(long n) {
		double pentagon = (Math.sqrt(1 + 24 * n) + 1) / 6;
		return pentagon == (long) pentagon;
	}

}
