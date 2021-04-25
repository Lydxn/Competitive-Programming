import java.util.Scanner;

public class DMOPC_2015_C2_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] xyene = new int[N];
		for (int i = 0; i < xyene.length; i++) {
			xyene[i] = in.nextInt();
		}

		int[] fatal = new int[N];
		for (int i = 0; i < fatal.length; i++) {
			fatal[i] = in.nextInt();
		}

		int xCount = 0, fCount = 0;
		for (int i = 0; i < N; i++) {
			if (xyene[i] > fatal[i]) 	  xCount++;
			else if (xyene[i] < fatal[i]) fCount++;
		}

		System.out.println(xCount + " " + fCount);
		System.out.println(xCount > fCount ? "Xyene" : (xCount < fCount ? "FatalEagle" : "Tie"));
	}

}
