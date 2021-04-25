import java.util.ArrayList;
import java.util.Scanner;

public class P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sets = in.nextInt();
		in.nextLine();
		for (int i = 0; i < sets; i++) {
			String s11 = in.nextLine();
			ArrayList<Integer> l11 = new ArrayList<Integer>(s11.length());
			for (int j = 0; j < s11.length(); j++) {
				l11.add(Character.getNumericValue(s11.charAt(j)));
			}

			System.out.println(s11);
			while ((l11.get(0) != 0 && l11.size() > 2) || (l11.get(0) == 0 && l11.size() > 3)) {
				int digit = l11.size() - 1;
				if (l11.get(digit - 1) >= l11.get(digit)) {
					l11.set(digit - 1, l11.get(digit - 1) - l11.get(digit));
				} else {
					l11.set(digit - 1, l11.get(digit - 1) - l11.get(digit) + 10);
					int l = digit - 2;
					for (; l11.get(l) == 0; l--) {
						l11.set(l, 9);
					}
					l11.set(l, l11.get(l) - 1);
				}
				l11.remove(digit);

				for (int k = 0; k < l11.size(); k++) {
					if (!(l11.get(k) == 0 && k == 0)) {
						System.out.print(l11.get(k));
					}
				}
				System.out.println();
			}

			String num = "";
			for (int m = 0; m < l11.size(); m++) {
				num += l11.get(m);
			}
			System.out.println("The number " + s11 + " is " + (Integer.parseInt(num) % 11 == 0 ? "" : "not ") + "divisible by 11.");
			if (i != sets - 1) System.out.println();
		}
	}

}
