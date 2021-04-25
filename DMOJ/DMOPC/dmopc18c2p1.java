import java.io.*;
import java.util.*;

public class dmopc18c2p1 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int P = in.nextInt();
		
		int[] corners = new int[4];
		for (int i = 0; i < P; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			
			corners[0] = Math.min(corners[0], x);
			corners[1] = Math.max(corners[1], x);
			corners[2] = Math.min(corners[2], y);
			corners[3] = Math.max(corners[3], y);
		}
		System.out.println(2 * ((corners[3] - corners[2]) + (corners[1] - corners[0])));
	}
}
