import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();

		String[] status = new String[N];
		for (int i = 0; i < status.length; i++) {
			status[i] = in.nextLine();
		}

		int totalWA = (int) Arrays.stream(status).filter(i -> i.equals("WA")).count();
		int WA = 0;
		int IR = 0;

		for (int i = 0; i < status.length; i++) {
			switch (status[i]) {
			case "WA":
				System.out.println(++WA <= (int) (totalWA * 0.3) ? "AC" : "WA");
				break;
			case "IR":
				System.out.println(++IR <= 10 ? "AC" : (IR <= 20 ? "WA" : "IR"));
				break;
			case "TLE":
				System.out.println("WA");
				break;
			case "AC":
				System.out.println("AC");
				break;
			}
		}
	}

}
