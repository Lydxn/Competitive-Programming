import java.util.Scanner;

public class P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			System.out.println((1000 * in.nextInt() + 692999) / 693000 * 1000);
		}
	}

}
