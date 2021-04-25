import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int H = in.nextInt();
			int V = in.nextInt();

			int x = 50;
			int y = 25;

			while (x > 0 && y > 0 && x < 100 && y < 50) {
				x += H;
				y += V;
			}
			System.out.println(x + "," + y);
		}
    }
}
