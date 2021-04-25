package DMOJ;
import java.util.Scanner;

public class Christmas_Music {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		int fifthDir = 0;
		int prev = -1;
		
		for (int i = 0; i < N; i++) {
			String note = in.nextLine();
			int num = toNum(note);
			
			int diff = Math.abs(num - prev);
			if (fifthDir != 0 && ((num - prev) * fifthDir > 0 || diff >= 4)) {
				System.out.println("Salieri's music");
				return;
			} else if (prev != -1) {
				if (diff >= 7) {
					System.out.println("Salieri's music");
					return;
				} else {
					fifthDir = diff >= 4 ? (num > prev ? 1 : -1) : 0;
				}
			}
			prev = num;
		}
		System.out.println("Melodious!");
	}
	
	private static int toNum(String note) {
		return "CDEFGAB".indexOf(note.charAt(0)) + (note.charAt(1) - '0') * 7;
	}

}
