import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int I = in.nextInt();

		int sum = 0;
		for (int i = 0; i < I; i++) {
			sum += in.nextInt();
		}

		int S = in.nextInt();
		for (int i = 1; i <= S; i++) {
			sum += in.nextInt();
			System.out.println(sum / (float) (i + I));
		}
	}

}
