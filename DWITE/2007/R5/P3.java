import java.io.*;
import java.util.*;

public class P3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			System.out.println(Integer.bitCount(in.nextInt()) % 2);
		}
    }
}
