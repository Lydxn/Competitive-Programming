import java.io.*;
import java.util.*;

public class P3 {
    static int[][] friends;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int n = in.nextInt();

			friends = new int[n][2];
			for (int j = 0; j < friends.length; j++) {
				friends[j][0] = in.nextInt();
				friends[j][1] = in.nextInt();

				if ((friends[j][0] == 1 && friends[j][1] == 2) || (friends[j][0] == 2 && friends[j][1] == 1)) {
					friends[j][0] = 0;
					friends[j][1] = 0;
				}
			}

			SortedSet<Integer> friends1 = new TreeSet<Integer>();
			invite(friends1, 1, 1);
			friends1.remove(1);

			SortedSet<Integer> friends2 = new TreeSet<Integer>();
			invite(friends2, 2, 2);
			friends1.removeAll(friends2);

			if (friends1.isEmpty()) {
				System.out.println("none");
			} else {
				for (int f : friends1) {
					System.out.print(f + " ");
				}
				System.out.println();
			}
		}
	}

	private static void invite(Set<Integer> nodes, int degree, int node) {
		if (nodes.contains(node)) {
			return;
		} else {
			nodes.add(node);
			if (degree > 0) {
				for (int[] i : friends) {
					for (int j = 0; j < i.length; j++) {
						if (i[j] == node) {
							invite(nodes, degree - 1, i[j ^ 1]);
						}
					}
				}
			}
		}
	}
}
