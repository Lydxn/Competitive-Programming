package euler100;

public class P063 {

	public static void main(String[] args) {
		int count = 0;
		for (int i = 1; i < 22; i++) {
			count += 10 - Math.ceil(Math.pow(10, 1 - 1.0 / i));
		}
		System.out.println(count);
	}

}
