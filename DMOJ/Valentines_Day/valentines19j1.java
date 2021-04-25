package DMOJ.Valentines_Day;
import java.util.Scanner;

public class Valentines_Day_2019_J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		for (int i = 0; i < N; i++) {
			int rating = in.nextInt();
			
			if (rating < 1000) {
				System.out.println("Newbie");
			} else if (rating < 1200) {
				System.out.println("Amateur");
			} else if (rating < 1500) {
				System.out.println("Expert");
			} else if (rating < 1800) {
				System.out.println("Candidate Master");
			} else if (rating < 2200) {
				System.out.println("Master");
			} else if (rating < 3000) {
				System.out.println("Grandmaster");
			} else if (rating < 4000) {
				System.out.println("Target");
			} else {
				System.out.println("Rainbow Master");
			}
		}
	}	

}
