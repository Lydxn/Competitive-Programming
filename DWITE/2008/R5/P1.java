import java.io.*;
import java.util.*;

public class P1 {

    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			String s1 = in.nextLine();
			String s2 = in.nextLine();

			int res = 0;
			for (int j = 0; j < Math.min(s1.length(), s2.length()) && s1.charAt(j) == s2.charAt(j); j++, res++);
			System.out.println(res);
		}
	}

}
