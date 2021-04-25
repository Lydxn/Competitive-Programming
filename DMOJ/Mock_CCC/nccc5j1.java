import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		String card = in.nextLine();

		System.out.println(card.contains("CCC") ? "NO" : "YES");
    }
}
