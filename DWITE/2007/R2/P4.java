import java.io.*;
import java.util.*;

public class P4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		main: for (int i = 0; i < 5; i++) {
			String brackets = in.nextLine();
			Stack<Character> st = new Stack<Character>();

			for (int j = 0; j < brackets.length(); j++) {
				char ch = brackets.charAt(j);
				switch (ch) {
					case '(':
					case '[':
					case '{':
						st.push(ch);
						break;
					case ')':
						if (st.isEmpty() || st.pop() != '(') {
							System.out.println("not balanced");
							continue main;
						}
						break;
					case ']':
						if (st.isEmpty() || st.pop() != '[') {
							System.out.println("not balanced");
							continue main;
						}
						break;
					case '}':
						if (st.isEmpty() || st.pop() != '{') {
							System.out.println("not balanced");
							continue main;
						}
						break;
					default:
						break;
				}
			}
			System.out.println("balanced");
		}
    }
}
