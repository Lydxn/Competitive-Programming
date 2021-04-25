package ccc_1997;
import java.util.ArrayList;
import java.util.Scanner;

public class P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sets = in.nextInt();
		in.nextLine();
		for (int i = 0; i < sets; i++) {
			ArrayList<String[]> lines = new ArrayList<String[]>();
			
			String line = in.nextLine();
			while (!line.isEmpty()) {
				lines.add(line.split(" "));
				line = in.nextLine();
			}
			
			ArrayList<String> dict = new ArrayList<String>();
			for (int j = 0; j < lines.size(); j++) {
				String res = "";
				for (int k = 0; k < lines.get(j).length; k++) {
					String str = lines.get(j)[k];
					if (dict.indexOf(str) == -1) {
						res += str + " ";
						dict.add(str);
					} else {
						res += dict.indexOf(str) + 1 + " ";
					}
				}
				System.out.println(res.trim());
			}
			System.out.println();
		}
	}

}
