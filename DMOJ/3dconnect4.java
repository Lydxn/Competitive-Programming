package DMOJ;
import java.util.Scanner;

public class Three_Dimensional_Connect_4 {
	
	static boolean[][][] connect3D = new boolean[6][6][6];

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				String line = in.nextLine();
				for (int k = 0; k < 6; k++) {
					connect3D[i][j][k] = line.charAt(k) == 'R' ? true : false;
				}
			}
			
			if (i != 5) {
				in.nextLine();
			}
		}
		
		int occurences = occurences(3, 6, 6) + 
						 occurences(6, 3, 6) + 
						 occurences(6, 6, 3);
		System.out.println(occurences == 0 ? "lost" : occurences);
	}
	
	private static int occurences(int x, int y, int z) {
		int sum = 0;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				for (int k = 0; k < z; k++) {
					boolean connected = true;
					for (int s = 0; s < 4; s++) {
						if (!connect3D[x == 3 ? i + s : i]
									  [y == 3 ? j + s : j]
									  [z == 3 ? k + s : k]) {
							connected = false;
							break;
						}
					}
					
					if (connected) {
						sum++;
					}
				}
			}
		}
		return sum;
	}

}