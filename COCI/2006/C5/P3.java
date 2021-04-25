package COCI;
import java.util.Scanner;

public class COCI_2006_C5_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String playerA = in.next();
		String playerB = in.next();
		int N = in.nextInt();
		in.nextLine();
		
		outer: for (int i = 0; i < N; i++) {
			String[] match = in.nextLine().split(" ");
			if (match.length == 1 || match.length > 3) {
				System.out.println("ne");
				continue outer;
			}

			int winsA = 0;
			int winsB = 0;
			for (int j = 0; j < match.length; j++) {
				String[] set = match[j].split(":");
				int A = Integer.parseInt(set[0]);
				int B = Integer.parseInt(set[1]);
				
				if ((A >= 6 && A >= B + 2 && (j == 2 || (j != 2 && B < 6))) || (B == 6 && A > B && j < 2)) {
					winsA++;
				} else if ((B >= 6 && B >= A + 2 && (j == 2 || (j != 2 && A < 6))) || (A == 6 && B > A && j < 2)) {
					winsB++;
				} else {
					System.out.println("ne");
					continue outer;
				}
			}
			
			System.out.println(Math.abs(winsA - winsB) >= 3 || 
							   winsA == winsB ||
							  (playerA.equals("federer") && winsB != 0) || 
							  (playerB.equals("federer") && winsA != 0)
							   ? "ne" : "da");
		}
	}

}