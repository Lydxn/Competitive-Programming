package euler100;

public class P044 {

	public static void main(String[] args) {
		for (int j = 1; ; j++) {
			int Pj = j * (3 * j - 1) / 2;
			for (int k = j - 1; k > 0; k--) {
				int Pk = k * (3 * k - 1) / 2;
				
				if (isPentagonal(Pj + Pk) && isPentagonal(Pj - Pk)) {
					System.out.println(Pj - Pk);
					return;
				}
			}
		}
	}
	
	private static boolean isPentagonal(int n) {
		double pentagon = (Math.sqrt(1 + 24 * n) + 1) / 6;
		return pentagon == (int) pentagon;
	}

}
