package ccc_1998;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		for (int i = 0; i < n; i++) {
			LinkedList<String> equation = new LinkedList<String>(Arrays.asList(in.nextLine().split(" ")));
			
			for (int j = 1; j < equation.size(); j++) {
				if (equation.get(j).equals("X")) {
					String leftX = equation.get(j - 1);
					String rightX = equation.get(j + 1);
					equation.remove(j + 1);
					equation.set(j, "(" + leftX + " X " + rightX + ")");
					equation.remove(j - 1);
					j--;
				}
			}
			
			for (int k = 1; k < equation.size(); k++) {
				if (equation.get(k).equals("+") || equation.get(k).equals("-")) {
					String symbol = equation.get(k);
					String leftPM = equation.get(k - 1);
					String rightPM = equation.get(k + 1);
					equation.remove(k + 1);
					equation.set(k, "(" + leftPM + " " + symbol + " " + rightPM + ")");
					equation.remove(k - 1);
					k--;
				}
			}
			
			String ordered = "";
			for (String l : equation) {
				ordered += l + " ";
			}
			System.out.println(ordered.substring(1, ordered.length() - 2));
		}
	}

}
