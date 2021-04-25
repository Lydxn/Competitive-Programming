import java.io.*;
import java.util.*;

public class dmopc18c2p0 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int a = in.nextInt();
		int R = in.nextInt();
		
		System.out.println(Math.min(R / a, N));
	}
}
