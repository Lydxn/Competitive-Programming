package euler100;

public class P009 {

	public static void main(String[] args) {
		for (int i = 1; ; i++) {
			for (int j = i + 1; j < 32; j++) {
				int a = j * j - i * i;
				int b = 2 * j * i;
				int c = j * j + i * i;
				
				if (a + b + c == 1000) {
					System.out.println(a + " " + b + " " + c);
					System.out.println(a * b * c);
					return;
				}
			}
		}
	}

}
