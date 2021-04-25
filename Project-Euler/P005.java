package euler100;

public class P005 {

	public static void main(String[] args) {
		for (long i = 2520; ; i += 2520) {
			if (divisible(i)) {
				System.out.println(i);
				return;
			}
		}
	}
	
	private static boolean divisible(long n) {
		for (int j = 11; j < 20; j++) {
			if (n % j != 0) {
				return false;
			}
		}
		return true;
	}

}

