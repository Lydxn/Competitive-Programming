package euler100;

public class P036 {

	public static void main(String[] args) {
		int sum = 0;
		for (int i = 0; i < 1000000; i++) {
			if (isPalin(Integer.toString(i)) && isPalin(Integer.toBinaryString(i))) {
				sum += i;
			}
		}
		System.out.println(sum);
	}
	
	private static boolean isPalin(String n) {
		for (int i = 0; i < n.length() / 2; i++) {
			if (n.charAt(i) != n.charAt(n.length() - i - 1)) {
				return false;
			}
		}
		return true;
	}
}
