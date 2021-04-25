package DMOJ;
import java.util.Scanner;

public class Lowest_Exam_Mark {

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int P = in.nextInt();
		int Q = in.nextInt();
		int W = in.nextInt();
		
		int correct = (int) Math.round((100 * (Q - P - 0.5) + P * W) / W);
		System.out.println(correct > 100 ? "DROP THE COURSE" : (correct < 0 ? 0 : correct));
    }

}
