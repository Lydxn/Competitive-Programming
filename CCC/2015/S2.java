package ccc_2015;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int J = in.nextInt();
		int A = in.nextInt();

		char[] jerseys = new char[J];
		for (int i = 0; i < jerseys.length; i++) {
			jerseys[i] = in.next().charAt(0);
		}
		
		int satisfied = 0;
		for (int i = 0; i < A; i++) {
			char size = in.next().charAt(0);
			int jersey = in.nextInt() - 1;
			
			if (fits(size, jerseys[jersey])) {
				satisfied++;
				jerseys[jersey] = ' ';
			}
		}
		System.out.println(satisfied);
	}
	
	private static boolean fits(char size, char jersey) {
		return (size == 'S' && (jersey == 'S' || jersey == 'M' || jersey == 'L')) || 
			   (size == 'M' && (jersey == 'M' || jersey == 'L')) || 
			   (size == 'L' && (jersey == 'L'));
	}

}
