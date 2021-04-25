import java.io.*;
import java.util.*;

public class P2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			List<String> words = new LinkedList<String>(Arrays.asList(in.nextLine().split("[^A-Za-z]+")));
			words.removeIf(w -> w.length() < 4);
			System.out.println(words.size());
		}
    }
}
