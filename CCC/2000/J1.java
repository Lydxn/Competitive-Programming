import java.io.*;
import java.util.*;

public class J1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int startDay = in.nextInt();
		int numDay = in.nextInt();

		String spaces = "";
		for (int i = 1; i < startDay; i++) {
			spaces += "    ";
		}
		spaces = startDay == 1 ? spaces : spaces.substring(1);

		System.out.println("Sun Mon Tue Wed Thr Fri Sat");
		System.out.print(spaces);

		boolean nl = false;
		for (int j = 1; j <= numDay; j++) {
			if ((j + startDay - 2) % 7 == 0) {
				System.out.printf("%3d", j);
			} else {
				System.out.printf("%4d", j);
			}
			if ((j + startDay - 1) % 7 == 0) {
				System.out.println();
				if (j == numDay) nl = true;
			}
		}

		if (!nl) {
		    System.out.println();
		}
    }
}
