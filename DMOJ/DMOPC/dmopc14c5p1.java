import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int r = in.nextInt();
		int h = in.nextInt();

		System.out.println(Math.PI * r * r * h / 3);
	}
}
