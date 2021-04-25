package DMOJ;
import java.util.Scanner;

public class Bruno_And_Tennis {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		boolean bruno = true;
		boolean lob = false;
		
		for (int i = 0; i < N / 2; i++) {
			boolean swing1 = in.nextLine().equals("lob") ? true : false;
			boolean swing2 = in.nextLine().equals("lob") ? true : false;
			
			if (swing1 || swing2) {
				lob = true;
			}
			
			if (swing1 ^ swing2) {
				bruno = false;
			}
		}
		System.out.println(!lob ? "Not enough information" : (bruno ? "Possible Bruno" : "BruNO"));
	}

}
