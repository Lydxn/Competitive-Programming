package ccc_2004;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int aNum = in.nextInt();
		int nNum = in.nextInt();
		in.nextLine();
		
		String[] adj = new String[aNum];
		String[] noun = new String[nNum];
		
		for (int a = 0; a < aNum; a++) {
			adj[a] = in.nextLine();
		}
		
		for (int n = 0; n < nNum; n++) {
			noun[n] = in.nextLine();
		}
		
		for (String a : adj) {
			for (String n : noun) {
				System.out.println(a + " as " + n);
			}
		}
	}

}
