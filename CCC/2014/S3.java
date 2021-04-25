package ccc_2014;
import java.util.Scanner;
import java.util.Stack;

public class S3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			
			Stack<Integer> hill = new Stack<Integer>();
			Stack<Integer> branch = new Stack<Integer>();
			
			for (int j = 0; j < N; j++) {
				hill.add(in.nextInt());
			}
			
			int pour = 1;
			char yum = 'Y';
			while (pour <= N) {
				if (!hill.isEmpty() && hill.peek() == pour) {
					hill.pop();
					pour++;
				} else if (!branch.isEmpty() && branch.peek() == pour) {
					branch.pop();
					pour++;
				} else {
					if (hill.isEmpty()) {
						yum = 'N';
						break;
					}
					branch.push(hill.pop());
				}
			}
			System.out.println(yum);
		}
	}

}
