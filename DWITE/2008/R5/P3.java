import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			List<String> curr = new ArrayList<String>();
			for (String s : in.nextLine().split("/")) {
				if (!s.isEmpty()) {
					curr.add(s);
				}
			}

			String[] path = in.nextLine().split("/");
			for (String s : path) {
				if (s.equals("..")) {
					if (!curr.isEmpty()) {
						curr.remove(curr.size() - 1);
					}
				} else if (!s.equals(".")) {
					curr.add(s);
				}
			}

			for (String s : curr) System.out.print("/" + s);
			System.out.println("/");
		}
	}

}
