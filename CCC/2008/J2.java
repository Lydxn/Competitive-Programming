package ccc_2008;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String[] mp = {"A", "B", "C", "D", "E"};
		
		while (true) {
			System.out.print("Button number: ");
			int b = in.nextInt();
			System.out.print("Number of presses: ");
			int n = in.nextInt();
			
			for (int i = 0; i < n; i++) {
				if (b == 1) {
					String mr1 = mp[0];
					mp[0] = mp[1];
					mp[1] = mp[2];
					mp[2] = mp[3];
					mp[3] = mp[4];
					mp[4] = mr1;
				} else if (b == 2) {
					String mr2 = mp[0];
					mp[0] = mp[4];
					mp[4] = mp[3];
					mp[3] = mp[2];
					mp[2] = mp[1];
					mp[1] = mr2;
				} else if (b == 3) {
					String mr3 = mp[0];
					mp[0] = mp[1];
					mp[1] = mr3;
				} else {
					System.out.printf("%s %s %s %s %s\n", mp[0], mp[1], mp[2], mp[3], mp[4]);
					return;
				}
			}
		}
	}

}
