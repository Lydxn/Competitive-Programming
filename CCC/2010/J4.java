package ccc_2010;
import java.util.Scanner;

public class J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		while (true) {
			int n = in.nextInt();
			if (n == 0) {
				return;
			}

			int[] temp = new int[n];
			for (int i = 0; i < temp.length; i++) {
				temp[i] = in.nextInt();
			}
			
			int[] changes = new int[temp.length - 1];
			for (int i = 0; i < n - 1; i++) {
				changes[i] = temp[i + 1] - temp[i];
			}

			int size = 1;
            outer: for (; size < changes.length; size++) {
            	for (int k = 1; k < changes.length; k++) {
            		if (changes[k] != changes[k % size]) {
            			continue outer;
            		}
            	}
            	break;
            }
			System.out.println(n == 1 ? 0 : size);
		}
	}

}
