package ccc_1996;
import java.util.Scanner;

public class P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int pairs = in.nextInt();
		
		for (int i = 0; i < pairs; i++) {
			int n = in.nextInt();
			int k = in.nextInt();
			
			String bit = "";
			for (int j = 0; j < n; j++) {
				bit += j < k ? "1" : "0";
			}
			
			int tenN = bit.lastIndexOf("10");
			System.out.println("The bit patterns are");
			
			while (tenN >= 0) {
				System.out.println(bit);
				StringBuilder tenS = new StringBuilder(bit.substring(tenN + 2));
				
				bit = bit.substring(0, tenN) + "01" + tenS.reverse();
				tenN = bit.lastIndexOf("10");
			}
			System.out.println(bit + "\n");
		}
	}

}
