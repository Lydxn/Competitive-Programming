import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
			for (int i = 0; i < 5; i++) {
			double d = Math.toRadians(in.nextInt());
			int p = in.nextInt();

			double time = Math.sin(d) * p / 4.905;
			double dist = Math.cos(d) * p * time;
			System.out.println((int) Math.round(dist));
		}
    }
}
