import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		int D = in.nextInt();

		System.out.println(N * (int) Math.pow(K, D));
	}
}
