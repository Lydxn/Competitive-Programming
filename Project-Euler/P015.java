package euler100;

public class P015 {
	
	public static void main(String[] args) {
		long paths = 1;
		for (int i = 0; i < 20; i++) {
			paths *= 40 - i;
			paths /= i + 1;
		}
		System.out.println(paths);
	}
	
}
