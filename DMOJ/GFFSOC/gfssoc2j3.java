package DMOJ;
import java.util.Scanner;

public class Equation_Solver {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String[] equation = in.nextLine().split(" ");
		
		int res = Integer.parseInt(equation[0]);
		for (int i = 1; i < equation.length - 1; i += 2) {
			char oper = equation[i].charAt(0);
			int val = Integer.parseInt(equation[i + 1]);
			
			res = oper == 'P' ? res + val : res - val;
		}
		System.out.println(res);
	}
	
}