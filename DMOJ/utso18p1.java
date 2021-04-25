import java.io.*;
import java.util.*;

public class utso18p1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		long N = in.nextInt();
		long M = in.nextInt();

		long sum = N + M;
		long diff = Math.abs(N - M);
		long mult = N * M;

		System.out.println(Math.max(sum, Math.max(diff, mult)));
    }
}
