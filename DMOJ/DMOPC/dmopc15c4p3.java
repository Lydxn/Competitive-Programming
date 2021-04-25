import java.util.Scanner;

public class DMOPC_2015_C4_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int G = in.nextInt();

		outer: for (int i = 0; i < G; i++) {
			int N = in.nextInt();

			int[] minions = new int[N];
			for (int j = 0; j < minions.length; j++) {
				minions[j] = in.nextInt();
			}

			int Hi = in.nextInt(), Hm = in.nextInt();
			for (int j = 0; j < 1 << N; j++) {
				int ionutpop = Hi, taunt = Hm;
				for (int k = 0; k < N; k++) {
					if ((j >> k & 1) != 0) ionutpop -= minions[k];
					else 				   taunt -= minions[k];
				}

				if (ionutpop <= 0 && taunt <= 0) {
					System.out.println("LETHAL");
					continue outer;
				}
			}
			System.out.println("NOT LETHAL");
		}
	}

}
