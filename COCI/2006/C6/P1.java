package COCI;
import java.util.Scanner;

public class COCI_2006_C6_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		String[] child = new String[101];
		int warn = 0;
		
		for (int i = 0; i <= N; i++) {
			child[i] = in.nextLine();
			int take = 0;
			
			for (int j = 1; j < i; j++) {
				if (child[i].equals(child[j])) {
					take++;
				}
			}
			
			if (i - take <= take) {
				warn++;
			}
		}
		System.out.println(warn - 1);
	}

}