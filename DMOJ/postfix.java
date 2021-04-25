package DMOJ;
import java.util.Scanner;
import java.util.Stack;

public class Postfix_Notation {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char[] equation = in.nextLine().toCharArray();
		
		Stack<Double> stack = new Stack<Double>();
		for (int i = 0; i < equation.length; i++) {
			char ch = equation[i];
			
			if ("+-*/%^".indexOf(ch) != -1) {
				switch (ch) {
				case '+':
					stack.push(stack.pop() + stack.pop());
					break;
				case '-':
					stack.push(-stack.pop() + stack.pop());
					break;
				case '*':
					stack.push(stack.pop() * stack.pop());
					break;
				case '/':
					stack.push(1 / stack.pop() * stack.pop());
					break;
				case '%':
					stack.push(stack.pop() % stack.pop());
					break;
				case '^':
					stack.push(Math.pow(stack.pop(), stack.pop()));
					break;
				}
			} else if (Character.isDigit(ch)) {
				stack.push(0.0);
				while (Character.isDigit(equation[i])) {
					stack.push(10 * stack.pop() + Character.getNumericValue(equation[i++]));
				}
			}
		}
		System.out.println(stack.pop());
	}

}