import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		float maxR = 0;
		String maxS = "";

		for (int i = 0; i < N; i++) {
			String S = in.next();
			float R = in.nextFloat();

			if (R >= maxR) {
				maxR = R;
				maxS = S;
			}
		}
		System.out.println(maxS);
	}

}
