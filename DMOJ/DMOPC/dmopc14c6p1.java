import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();

		int bessarion = -1;
		String[] stations = new String[N];

		for (int i = 0; i < stations.length; i++) {
			String station = in.nextLine();
			stations[i] = station;

			if (station.equals("Bessarion")) {
				bessarion = i;
			}
		}

		try {
			String left = stations[bessarion - 1];
			String right = stations[bessarion + 1];

			System.out.println((left.equals("Leslie") && right.equals("Bayview")) ||
					  		   (left.equals("Bayview") && right.equals("Leslie"))
					   			? 'Y' : 'N');
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println('N');
		}
	}

}
