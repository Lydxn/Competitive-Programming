package DMOJ;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Candidate {
	int id;
	int points;
	
	public Candidate (int id, int points) {
		this.id = id;
		this.points = points;
	}
}

public class Friendship_Is_A_Number {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		Candidate[] candidates = new Candidate[N];
		for (int i = 0; i < candidates.length; i++) {
			int T = in.nextInt();
			int prod = 1;
			
			for (int j = 0; j < T; j++) {
				prod *= in.nextInt();
			}
			candidates[i] = new Candidate(i + 1, prod);
		}
		
		Arrays.sort(candidates, new Comparator<Candidate>() {
			public int compare(Candidate o1, Candidate o2) {
				return Integer.compare(o2.points, o1.points);
			}
		});
		
		for (int i = 0; i < 3; i++) {
			System.out.println(candidates[i].id);
		}
	}

}