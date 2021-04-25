package DMOJ;
import java.io.*;
import java.util.*;

public class Mr_N_And_Presents {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int Q = Integer.parseInt(br.readLine());
		
		Deque<Integer> deque = new ArrayDeque<Integer>();
		for (int i = 0; i < Q; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			char instruction = st.nextToken().charAt(0);
			int student = Integer.parseInt(st.nextToken());

			switch (instruction) {
			case 'F':
				deque.offerFirst(student);
				break;
			case 'E':
				deque.offerLast(student);
				break;
			case 'R':
				deque.remove(student);
				break;
			}
		}
		
		for (int d : deque) {
			System.out.println(d);
		}
	}

}
