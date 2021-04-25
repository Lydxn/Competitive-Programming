package ECOO;
import java.util.*;
import java.io.*;

class Assignment {
	int deadline;
	float weight;
	
	public Assignment(int deadline, float weight) {
		this.deadline = deadline;
		this.weight = weight;
	}
}

public class ECOO_2018_R2_P2 {

	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int i = 0; i < 10; i++) {
			int N = Integer.parseInt(br.readLine());
			
			Assignment[] assignments = new Assignment[N];
			for (int j = 0; j < assignments.length; j++) {
			    StringTokenizer st = new StringTokenizer(br.readLine());
				assignments[j] = new Assignment(Integer.parseInt(st.nextToken()), Float.parseFloat(st.nextToken()));
			}
			
			Arrays.sort(assignments, new Comparator<Assignment>() {
				public int compare(Assignment o1, Assignment o2) {
					return Float.compare(o2.weight, o1.weight);
				}
			});
			
			TreeSet<Integer> deadlines = new TreeSet<Integer>();
			for (int j = 0; j < 1000001; j++) {
				deadlines.add(j);
			}
			
			float maxWeight = 0;
			for (Assignment a : assignments) {
				int index = deadlines.floor(a.deadline);
				if (index != 0) {
					maxWeight += a.weight;
					deadlines.remove(index);
				}
			}
			System.out.println(String.format("%.4f", maxWeight));
		}
	}

}