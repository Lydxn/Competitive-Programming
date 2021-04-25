package ccc_2008;
import java.util.Scanner;
import java.util.Stack;

public class S4 {
	
	static int[] cards;
	static boolean[] visited;
	static int max;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			cards = new int[4];
			visited = new boolean[4];
			max = 0;
			
			for (int j = 0; j < 4; j++) {
				cards[j] = in.nextInt();
			}
			
			twentyFour(new Stack<Integer>(), 0);
			System.out.println(max);
		}
	}
	
	@SuppressWarnings("unchecked")
	private static void twentyFour(Stack<Integer> hand, int i) {
		if (hand.size() == 1 && i == 4) {
			int res = hand.peek();
			if (max < res && res <= 24) {
				max = res;
			}
			return;
		}
		
		if (i < 4) {
			for (int j = 0; j < 4; j++) {
				if (!visited[j]) {
					visited[j] = true;
					Stack<Integer> temp = (Stack<Integer>) hand.clone();
					
					temp.push(cards[j]);
					twentyFour((Stack<Integer>) temp.clone(), i + 1);
					temp.pop();
					
					visited[j] = false;
				}
			}
		}
		
		if (hand.size() > 1) {
			int a = hand.pop();
			int b = hand.pop();
			Stack<Integer> temp = (Stack<Integer>) hand.clone();
			
			for (int j = 0; j < 4; j++) {
				if (j == 3 && (b == 0 || a % b != 0)) {
					continue;
				}

				temp.push(operate(a, b, j));
				twentyFour((Stack<Integer>) temp.clone(), i);
				temp.pop();
			}
		}
	}
	
	private static int operate(int a, int b, int type) {
		switch (type) {
		case 0:
			return a + b;
		case 1:
			return a - b;
		case 2:
			return a * b;
		default:
			return a / b;
		}
	}

}
