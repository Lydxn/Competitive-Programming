import java.io.*;
import java.util.*;

public class P5 {
    static int[][] values = new int[5][5];
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		String[][] exprs = new String[5][5];
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				exprs[i][j] = in.nextLine();
			}
		}

		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					String expr = exprs[j][k];

					if (expr.charAt(0) == '=') {
						String[] split = expr.substring(1).split(" ");
						int n = convert(split[0]);

						for (int l = 1; l < split.length - 1; l++) {
							if (split[l].equals("+")) {
								n += convert(split[l + 1]);
							} else if (split[l].equals("-")) {
								n -= convert(split[l + 1]);
							} else if (split[l].equals("*")) {
								n *= convert(split[l + 1]);
							}
						}
						values[j][k] = n;
					} else {
						values[j][k] = Integer.parseInt(expr);
					}
				}
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				System.out.println(values[i][j]);
			}
		}
	}

	public static int convert(String var) {
		char ch = var.charAt(0);
		return ch >= 'A' && ch <= 'E' ? values[var.charAt(0) - 'A'][var.charAt(1) - '1'] : Integer.parseInt(var);
	}
}
