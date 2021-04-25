package ccc_2010;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int A = 0;
		int B = 0;
		char X, Y;
		
		while (true) {
			int instruction = in.nextInt();
			switch (instruction) {
			case 1:
				X = in.next().charAt(0);
				int n = in.nextInt();

				if (X == 'A') {
					A = n;
				} else {
					B = n;
				}
				break;
			case 2:
				X = in.next().charAt(0);

				System.out.println(X == 'A' ? A : B);
				break;
			case 3:
				X = in.next().charAt(0);
				Y = in.next().charAt(0);
				
				if (X == 'A') {
					A += Y == 'A' ? A : B;
				} else {
					B += Y == 'A' ? A : B; 
				}
				break;
			case 4:
				X = in.next().charAt(0);
				Y = in.next().charAt(0);

				if (X == 'A') {
					A *= Y == 'A' ? A : B;
				} else {
					B *= Y == 'A' ? A : B; 
				}
				break;
			case 5:
				X = in.next().charAt(0);
				Y = in.next().charAt(0);

				if (X == 'A') {
					A -= Y == 'A' ? A : B;
				} else {
					B -= Y == 'A' ? A : B; 
				}
				break;
			case 6:
				X = in.next().charAt(0);
				Y = in.next().charAt(0);

				if (X == 'A') {
					A /= Y == 'A' ? A : B;
				} else {
					B /= Y == 'A' ? A : B; 
				}
				break;
			default:
				return;
			}
		}
	}

}
