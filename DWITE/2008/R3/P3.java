import java.io.*;
import java.util.*;

public class P3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			String[] cnv = in.nextLine().split(" ");
			HashMap<String, Integer> imperial = new HashMap<String, Integer>() {{
				put("oz", 1);
				put("gill", 5);
				put("pt", 20);
				put("qt", 40);
				put("gal", 160);
			}};

			System.out.println(Integer.parseInt(cnv[0]) * imperial.get(cnv[1]) / imperial.get(cnv[3]));
		}
    }
}
