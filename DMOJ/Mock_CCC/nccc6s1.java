import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int avg = 0;
		for (int i = 0; i < N; i++) {
			int num = in.nextInt();
			avg += num;
		}
		System.out.println(((double) (avg) / N) * 10 / 10);
    }
}
