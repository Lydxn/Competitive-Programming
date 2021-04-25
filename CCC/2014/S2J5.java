package ccc_2014;
import java.util.Scanner;

public class S2_J5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		String[] partner1 = in.nextLine().split(" ");
		String[] partner2 = in.nextLine().split(" ");
		
		for (int i = 0; i < N; i++) {
			int j = 0;
			for (; j < N; j++) {
				if (partner1[j].equals(partner2[i])) {
					break;
				}
			}
			
			if (!(partner1[i].equals(partner2[j])) || i == j) {
				System.out.println("bad");
				return;
			}
		}
		System.out.println("good");
	}

}
