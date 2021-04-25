import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int A = in.nextInt();
		int B = in.nextInt();

		if (A > B) {
			System.out.println("CS452");
		} else if (A < B) {
			System.out.println("PHIL145");
		}
    }
}
