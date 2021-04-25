import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class dmopc17c2p2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String S = in.nextLine();
		
		Deque<Character> stack = new ArrayDeque<Character>();
		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) == ')' && !stack.isEmpty() && stack.peek() == '(') stack.pop();
			else 																   stack.push(S.charAt(i));
		}
		System.out.println(stack.isEmpty() || (stack.size() == 2 && stack.pop() == stack.peek())? "YES" : "NO");
	}

}
