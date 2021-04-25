package ccc_2017;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		String[] swifts = in.nextLine().split("\\s+");
		String[] semaphores = in.nextLine().split("\\s+");
		
		int swiftPts = 0;
		int semaPts = 0;
		int K = 0;
		for (int i = 0; i < N; i++) {
			swiftPts += Integer.parseInt(swifts[i]);
			semaPts += Integer.parseInt(semaphores[i]);
			if (swiftPts == semaPts) {
				K = i + 1;
			}
		}
		System.out.println(K);
	}

}
