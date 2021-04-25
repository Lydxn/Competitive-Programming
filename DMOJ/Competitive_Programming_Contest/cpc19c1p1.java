import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		for (int i = 1, j = N; j > N / 2; i++, j--) {
			System.out.print((i <= N / 2 ? i + " " : "") + j + " ");
		}
	}
}
