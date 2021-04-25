package euler100;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class P061 {
	
	static int[][] polygonal = {polygonal(3), polygonal(4), polygonal(5), polygonal(6), polygonal(7), polygonal(8)};
	static int[] cyclic = new int[6];

	public static void main(String[] args) {
		for (int i = 0; i < polygonal[5].length; i++) {
			cyclic[5] = polygonal[5][i];
			if (find(5, 1)) {
				break;
			}
		}
		System.out.println(Arrays.stream(cyclic).sum());
	}

	private static boolean find(int last, int len) {
		for (int i = 0; i < cyclic.length; i++) {
			if (cyclic[i] != 0) {
				continue;
			}
			
			for (int j = 0; j < polygonal[i].length; j++) {
				boolean unique = true;
				for (int k = 0; k < cyclic.length; k++) {
					if (polygonal[i][j] == cyclic[k]) {
						unique = false;
						break;
					}
				}
				
				if (unique && isCyclic(cyclic[last], polygonal[i][j])) {
					cyclic[i] = polygonal[i][j];
					if (len == 5 && isCyclic(cyclic[i], cyclic[5]) || find(i, len + 1)) {
						return true;
					}
				}
			}
			cyclic[i] = 0;
		}
		return false;
	}

	public static boolean isCyclic(int l, int r) {
		return l % 100 == r / 100;
	}

	public static int[] polygonal(int type) {
		List<Integer> polygonal = new ArrayList<Integer>();
		int n = 0;
		for (int i = 1; n < 10000; i++) {
			n = (type - 2) * i * (i - 1) / 2 + i;
			if (n >= 1000 && n < 10000) {
				polygonal.add(n);
			}
		}
		return polygonal.stream().mapToInt(i -> i).toArray();
	}
 
}
