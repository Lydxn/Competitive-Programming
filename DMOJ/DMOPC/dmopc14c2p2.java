import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		in.nextLine();
		String[] portions = in.nextLine().split("X");

		List<String> cleaned = new ArrayList<String>();
		for (String p : portions) {
			if (!p.isEmpty()) {
				cleaned.add(p);
			}
		}

		System.out.println(cleaned.size());
		for (String c : cleaned) {
			System.out.println(c);
		}
	}
}
