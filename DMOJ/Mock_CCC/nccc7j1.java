import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int pearls = 0;
		for (int i = 0; i < 5; i++) {
			if (in.nextLine().equals("P")) {
				pearls++;
			}
		}
		System.out.println(pearls);
	}


}
