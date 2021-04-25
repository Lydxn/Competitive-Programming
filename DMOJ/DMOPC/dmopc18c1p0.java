import java.io.*;
import java.util.*;

public class dmopc18c1p0 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int B1 = in.nextInt();
		int B2 = in.nextInt();
		int B3 = in.nextInt();
		
		System.out.println(B1 <= B2 && B2 <= B3 ? "Good job!" : "Try again!");
	}
}
