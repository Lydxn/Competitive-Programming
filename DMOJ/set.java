package DMOJ;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Unique_Elements {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		Set<Integer> set = new HashSet<Integer>();
		for (int i = 0; i < N; i++) {
			set.add(in.nextInt());
		}
		System.out.println(set.size());
	}

}
