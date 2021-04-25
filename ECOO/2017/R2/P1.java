package ECOO;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ECOO_2017_R2_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int N = in.nextInt();
			int M = in.nextInt();
			
			Map<String, Character> key = new HashMap<String, Character>();
			for (int j = 0; j < 4; j++) {
				key.put(in.next(), in.next().charAt(0));
				in.nextLine();
			}

			char[][] tower = new char[M][N];
			tower[0] = in.nextLine().toCharArray();
			in.nextLine();
			
			for (int m = 0; m < M - 1; m++) {
				for (int n = 0; n < N; n++) {
					tower[m + 1][n] = key.get(Character.toString(tower[m][Math.floorMod(n - 1, N)]) +
											  Character.toString(tower[m][Math.floorMod(n + 1, N)]));
				}
			}
			System.out.println(String.valueOf(tower[M - 1]));
		}
	}

}
