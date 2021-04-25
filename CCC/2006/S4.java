package ccc_2006;
import java.util.Scanner;

public class S4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			int n = in.nextInt();
			if (n == 0) {
				return;
			}
			
			int[][] group = new int[n + 1][n + 1];
			for (int i = 1; i < group.length; i++) {
				for (int j = 1; j < group.length; j++) {
					group[i][j] = in.nextInt();
				}
			}
			 
			System.out.println(associativity(group) && inverse(group, identity(group)) ? "yes" : "no");
		}
	}
	
	private static boolean associativity(int[][] group) {
		for (int x = 1; x < group.length; x++) {
			for (int y = 1; y < group.length; y++) {
				for (int z = 1; z < group.length; z++) {
					if (group[x][group[y][z]] != group[group[x][y]][z]) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
	private static int identity(int[][] group) {
		int identity = -1;
		outer: for (int x = 1; x < group.length; x++) {
			for (int y = 1; y < group.length; y++) {
				if (group[x][y] != y) {
					continue outer;
				}
			}
			
			identity = x;
			break;
		}
		return identity;
	}
	
	private static boolean inverse(int[][] group, int identity) {
		if (identity == -1) {
			return false;
		} else {
			outer: for (int x = 1; x < group.length; x++) {
				for (int y = 1; y < group.length; y++) {
					if (group[x][y] == identity) {
						continue outer;
					}
				}
				return false;
			}
			return true;
		}
	}
	
}
