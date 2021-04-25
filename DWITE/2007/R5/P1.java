import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int N = in.nextInt();

			String[] heart = {" ~.~ ", "`   `", " \\./ "};

			for (String j : heart) {
				for (int k = 0; k < N; k++) {
					System.out.print(j);
				}
				System.out.println();
			}
		}
    }
}
