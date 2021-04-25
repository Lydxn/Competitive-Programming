import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int n = in.nextInt();

			HashSet<Integer> factors = new HashSet<Integer>();
			for (int j = 2; j <= n; j++) {
				while (n % j == 0) {
					factors.add(j);
					n /= j;
				}
			}
			System.out.println(factors.size() == 3 ? "valid" : "not");
		}
    }
}
