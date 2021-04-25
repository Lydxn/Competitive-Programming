import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 7; j++) {
				String tooth = in.nextLine();
				System.out.print(tooth.lastIndexOf('#') + 1);
			}

			System.out.println();
			if (in.hasNextLine())
			    in.nextLine();
		}
    }
}
