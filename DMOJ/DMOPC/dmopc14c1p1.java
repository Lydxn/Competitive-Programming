import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] marks = new int[N];
		for (int i = 0; i < marks.length; i++) {
			marks[i] = in.nextInt();
		}
		Arrays.sort(marks);

		int mid = marks.length / 2;
		System.out.println(marks.length % 2 == 0 ? Math.round((marks[mid] + marks[mid - 1]) / 2.0) : marks[mid]);
	}

}
