import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		if (N < 2) {
			System.out.println("not");
			return;
		}

		for (int i = 2; i <= Math.sqrt(N); i++) {
			if (N % i == 0) {
				System.out.println("not");
				return;
			}
		}
		System.out.println("prime");
    }
}
