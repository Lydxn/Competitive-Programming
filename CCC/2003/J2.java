package ccc_2003;
import java.util.Scanner;

public class J2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			System.out.println("Enter number of pictures:");
			int pictures = in.nextInt();
			
			if (pictures == 0) {
				return;
			}
			
			int l = (int) Math.round(Math.sqrt(pictures));
			while (pictures % l != 0) {
				l--;
			}
			
			int w = pictures / l;
			System.out.println("Minimum perimeter is " + (2 * (l + w)) + " with dimensions " + l + " x " + w + "\n");
		}
	}

}
