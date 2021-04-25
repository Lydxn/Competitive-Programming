import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int w = in.nextInt();
		int l = in.nextInt();
		int tile = in.nextInt();

		System.out.println((w / tile) * (l / tile));
	}
}
