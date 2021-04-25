package DMOJ;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Sandwich {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		String creation = in.nextLine();
		
		Deque<Integer> deque = new LinkedList<Integer>();
		for (int i = 0; i < N; i++) {
			if (creation.charAt(i) == '0') {
				deque.offerLast(i + 1);
			} else {
				deque.offerFirst(i + 1);
			}
		}
		
		for (int d : deque) {
			System.out.println(d);
		}
	}

}
