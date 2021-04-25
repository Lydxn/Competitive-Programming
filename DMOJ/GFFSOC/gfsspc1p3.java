package DMOJ;
import java.util.Arrays;
import java.util.Scanner;

public class Bruno_And_Beads {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		String beads = in.nextLine();
		
		int[] lasts = new int[3];	
		Arrays.fill(lasts, Integer.MAX_VALUE);
		
		for (int i = 0; i < N; i++) {
			int col = beads.charAt(i) == 'R' ? 0 : (beads.charAt(i) == 'Y' ? 1 : 2);
			if (i - lasts[col] > 1) {
				System.out.println("FIX YOUR BEADS!");
				return;
			}
			lasts[col] = i;
		}
		System.out.println("Organized");
	}

}