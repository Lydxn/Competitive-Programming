package ccc_1997;
import java.util.Scanner;

public class P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		for (int i = 0; i < n; i++) {
			int sNum = in.nextInt();
			int vNum = in.nextInt();
			int oNum = in.nextInt();
			in.nextLine();
			
			String[] subject = new String[sNum];
			String[] verb = new String[vNum];
			String[] object = new String[oNum];
			
			for (int s = 0; s < sNum; s++) {
				subject[s] = in.nextLine();
			}
			
			for (int v = 0; v < vNum; v++) {
				verb[v] = in.nextLine();
			}

			for (int o = 0; o < oNum; o++) {
				object[o] = in.nextLine();
			}
			
			for (String s : subject) {
				for (String v : verb) {
					for (String o : object) {
						System.out.println(s + " " + v + " " + o + ".");
					}
				}
			}
			System.out.println();
		}
	}

}
