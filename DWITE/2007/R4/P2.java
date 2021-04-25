import java.io.*;
import java.util.*;

public class P2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			Score[] scores = new Score[5];
			for (int j = 0; j < 5; j++) {
				String[] st = in.nextLine().split(" ", 2);
				int score = Integer.parseInt(st[0]);
				String name = st[1];

				scores[j] = new Score(score, name);
			}

			Arrays.sort(scores);
			for (Score s : scores) {
				System.out.println(s.name);
			}
		}
    }
}

final class Score implements Comparable<Score> {
	int score;
	String name;

	public Score(int score, String name) {
		this.score = score;
		this.name = name;
	}

	public int compareTo(Score o) {
		return Integer.compare(o.score, score);
	}

}
